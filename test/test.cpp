#include "AreaCircle.h"
#include "AreaTriangle.h"
#include "PerimeterCircle.h"
#include "PerimeterTriangle.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Circle area", "[AreaCircle]")
{
    REQUIRE(AreaCircle(1) == 3.14);
    REQUIRE(AreaCircle(2.5) == 19.625);
    REQUIRE(AreaCircle(5) == 78.5);
    REQUIRE(AreaCircle(10) == 31.4);
}

TEST_CASE("Triangle area", "[AreaTriangle]")
{
    REQUIRE(AreaTriangle(1, 1, 1, 1, 1, 1) == 0);
    REQUIRE(AreaTriangle(0, 0, 3, 0, 0, 4) == 12);
    REQUIRE(AreaTriangle(7, 5, 2, 0, 0, 4) == 30);
    REQUIRE(AreaTriangle(9, 0, 0, 1, 2, 8) == 65);
}

TEST_CASE("Circle perimeter", "[PerimeterCircle]")
{
    REQUIRE(PerimeterCircle(1) == 6.28);
    REQUIRE(PerimeterCircle(2.5) == 15.7);
    REQUIRE(PerimeterCircle(5) == 31.4);
    REQUIRE(PerimeterCircle(10) == 62.8);
}

TEST_CASE("Triangle perimeter", "[PerimeterTriangle]")
{
    REQUIRE(PerimeterTriangle(1, 1, 1, 1, 1, 1) == 0);
    REQUIRE(PerimeterTriangle(0, 0, 3, 0, 0, 4) == 12);
    REQUIRE(PerimeterTriangle(2, 2, 8, 2, 2, 10) == 24);
    REQUIRE(PerimeterTriangle(3, 3, 6, 3, 3, 7) == 12);
}
