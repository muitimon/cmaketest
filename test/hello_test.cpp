#include "hello.h"
#include "catch.hpp"

TEST_CASE("Hello Test", "[hello]"){
    REQUIRE( greetings("kanegae") == "Hello, kanegae");
    REQUIRE( greetings("") == "Hello, ");
}