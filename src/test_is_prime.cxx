#include <catch.hpp>
#include <math/primes.h>

TEST_CASE("Testing is_prime function", "[isPrime]") {
    SECTION("Testing for numbers not being prime") {
        REQUIRE(!math::isPrime(0));
        REQUIRE(!math::isPrime(1));
        REQUIRE(!math::isPrime(4));
    }

    SECTION("Testing for numbers being prime") {
        REQUIRE(math::isPrime(2));
        REQUIRE(math::isPrime(3));
        REQUIRE(math::isPrime(5));
        REQUIRE(math::isPrime(7));
        REQUIRE(math::isPrime(11));
        REQUIRE(math::isPrime(13));
    }
}
