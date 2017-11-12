/**
 * @author  Thomas Lehmann
 * @file    primes.h
 *
 * Copyright (c) 2017 Thomas Lehmann
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
 * documentation files (the "Software"), to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies
 * or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#ifndef __primes_h__
#define __primes_h__

#include <vector>
#include <algorithm>
#include <cmath>
#include <omp.h>

namespace math {

template <typename T>
bool isPrime(const T n) {
    if (n < 2) return false;
    if (n % 2 == 0) return n == 2;

    const auto d = static_cast<T>(std::sqrt(n));
    for (T k = 3; k <= d; k += 2) {
        if (n % k == 0) return false;
    }
    return true;
}

template <typename T>
using Primes = std::vector<T>;

template <typename T>
Primes<T> createPrimes(const T fromValue, const T toValue) {
    Primes<T> primes;

    if (fromValue >= 2) {
        primes.push_back(2);
    }

    auto first = fromValue;
    if (first % 2 == 0) {
        ++first;
    }

    for (T current = first; current <= toValue; current += 2) {
        if (isPrime(current)) {
            primes.push_back(current);
        }
    }

    return primes;
}

template <typename T>
Primes<T> createPrimesOMP(const T fromValue, const T toValue, const T chunks=2) {
    Primes<T> primes;

    if (fromValue >= 2) {
        primes.push_back(2);
    }

    // using chunks of computation avoiding that each call
    // of isPrime is parallelized
    const T chunkSize = (toValue - fromValue) / chunks;

    #pragma omp parallel for
    for (T chunk = 0; chunk < chunks; ++chunk) {
        T current = fromValue + chunk * chunkSize;
        const T last = (chunk+1 == chunks)? toValue: current + chunkSize;

        if (current % 2 == 0) {
            ++current;
        }

        for (; current <= last; current += 2) {
            if (isPrime(current)) {
                #pragma omp critical
                primes.push_back(current);
            }
        }
    }

    // unavoidable since parallelism indicates unordered results
    std::sort(primes.begin(), primes.end());
    return primes;
}

}

#endif
