#include <catch.hpp>
#include <math/primes.h>

#include <fstream>
#include <string>

template <typename T>
math::Primes<T> readPrimes(const std::string& pathAndFileName, const T limit=-1) {
    std::fstream stream(pathAndFileName);
    math::Primes<T> primes;
    T prime;
    T count =  (limit < 0)? 0: limit;

    while (stream >> prime && (limit < 0 || count > 0)) {
        primes.push_back(prime);
        --count;
    }

    stream.close();
    return primes;
}

TEST_CASE("Testing creation of primes", "[createPrimes") {
    const math::Primes<int> expected = readPrimes<int>("primes.txt");
    const int maxNumber = expected[expected.size()-1];

    SECTION("Testing no parallelization") {
        REQUIRE(math::createPrimes(2, maxNumber) == expected);
    }

    SECTION("Testing parallelization with OMP") {
        REQUIRE(math::createPrimesOMP(2, maxNumber, 4) == expected);
    }

    SECTION("Testing parallelization with fibers") {
        REQUIRE(math::createPrimesFiber(2, maxNumber, 4) == expected);
    }
}

