#include "AreaCircle.h"
#include "AreaTriangle.h"
#include "PerimeterCircle.h"
#include "PerimeterTriangle.h"
#include "IntersectCircle.h"
#include "SegmentCheck.h"
#include "Intersection.h"
#include "Figure.h"
#include "TriangleAndCircleInf.h"
#include "CircleCheck.h"
#include "TriangleCheck.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Circle area", "[AreaCircle]")
{
    REQUIRE(AreaCircle(1) == 3.14);
    REQUIRE(AreaCircle(2.5) == 19.625);
    REQUIRE(AreaCircle(5) == 78.5);
    REQUIRE(AreaCircle(10) == 314);
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
    REQUIRE(PerimeterCircle(3) == 18.84);
    REQUIRE(PerimeterCircle(6) == 37.68);
    REQUIRE(PerimeterCircle(11) == 69.08);
}

TEST_CASE("Triangle perimeter", "[PerimeterTriangle]")
{
    REQUIRE(PerimeterTriangle(1, 1, 1, 1, 1, 1) == 0);
    REQUIRE(PerimeterTriangle(0, 0, 3, 0, 0, 4) == 12);
    REQUIRE(PerimeterTriangle(2, 2, 8, 2, 2, 10) == 24);
    REQUIRE(PerimeterTriangle(3, 3, 6, 3, 3, 7) == 12);
}

TEST_CASE("Circle intersect", "[IntersectCircle]")
{
    REQUIRE(IntersectCircle(0, 0, 5, 100, 100, 5) == false);
    REQUIRE(IntersectCircle(0, 0, 3, 0, 0, 4) == false);
    REQUIRE(IntersectCircle(3, 3, 3, 0, 0, 2) == true);
    REQUIRE(IntersectCircle(0, 0, 7, 7, 0, 4) == true);
}

TEST_CASE("Check segment", "[SegmentCheck]")
{
    REQUIRE(SegmentCheck(0, 5, 3, 4, 5, 4, 3) == true);
    REQUIRE(SegmentCheck(2, 2, 2, 7, 0, 0, 4) == true);
    REQUIRE(SegmentCheck(7, 2, 2, 7, 0, 0, 4) == false);
    REQUIRE(SegmentCheck(0, 5, 1, 0, 5, 4, 3) == false);
}

TEST_CASE("Triangle And Circle Inf", "[TriangleAndCircleInf]")
{
    Figure tri1, cir1;
    tri1.x = 1;
    tri1.y = 0;
    tri1.x1 = 0;
    tri1.y1 = 5;
    tri1.x2 = 3;
    tri1.y2 = 4;
    cir1.x = 5;
    cir1.y = 4;
    cir1.r = 3;
    REQUIRE(TriangleAndCircleInf(tri1, cir1) == true);
    tri1.x2 = 1;
    tri1.y2 = 6;
    REQUIRE(TriangleAndCircleInf(tri1, cir1) == false);
    tri1.x = 3;
    tri1.y = 3;
    REQUIRE(TriangleAndCircleInf(tri1, cir1) == true);
    cir1.r = 2;
    REQUIRE(TriangleAndCircleInf(tri1, cir1) == false);
}

TEST_CASE("Intersection", "[Intersection]")
{
    Figure tri1, tri2;
    tri1.x = 2;
    tri1.y = 5;
    tri1.x1 = 6;
    tri1.y1 = 11;
    tri1.x2 = 9;
    tri1.y2 = 5;
    tri2.x = 4;
    tri2.y = 0;
    tri2.x1 = 8;
    tri2.y1 = 7;
    tri2.x2 = 12;
    tri2.y2 = 2;
    REQUIRE(Intersection(tri1, tri2) == true);
    tri1.x = 3;
    tri1.y = 8;
    REQUIRE(Intersection(tri1, tri2) == true);
    tri1.x2 = 7;
    tri1.y2 = 6;
    REQUIRE(Intersection(tri1, tri2) == false);
    tri1.x1 = 11;
    tri1.y1 = 11;
    REQUIRE(Intersection(tri1, tri2) == false);
}

TEST_CASE("Circle check", "[CircleCheck]")
{
    REQUIRE(CircleCheck(1) == true);
    REQUIRE(CircleCheck(5) == true);
    REQUIRE(CircleCheck(0) == false);
    REQUIRE(CircleCheck(-1) == false);
}

TEST_CASE("Triangle Check", "[TriangleCheck]")
{
    Figure tr;
    tr.x = 1;
    tr.y = 5;
    tr.x1 = 3;
    tr.y1 = 3;
    tr.x2 = 5;
    tr.y2 = 1;
    REQUIRE(TriangleCheck(tr) == false);
    tr.x2 = 6;
    tr.y2 = 0;
    REQUIRE(TriangleCheck(tr) == false);
    tr.y2 = 3;
    REQUIRE(TriangleCheck(tr) == true);
    tr.x = 4;
    REQUIRE(TriangleCheck(tr) == true);
}
