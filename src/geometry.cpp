#include "AreaCircle.h"
#include "AreaTriangle.h"
#include "CircleCheck.h"
#include "Figure.h"
#include "IntersectCircle.h"
#include "Intersection.h"
#include "PerimeterCircle.h"
#include "PerimeterTriangle.h"
#include "SegmentCheck.h"
#include "TriangleAndCircleInf.h"
#include "TriangleCheck.h"
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
Again:
    cout << "Choose two figures: 1.Circle 2.Triangle" << endl;
    int f, f1;
    cin >> f >> f1;

    Figure cir1;
    Figure tri1;
    Figure cir2;
    Figure tri2;

    if (f1 <= 0 || f <= 0 || f1 > 2 || f > 2) {
        cout << "Error input data" << endl;
        goto Again;
        return 0;
    }

    if (f == 1 and f1 == 1) {
        cout << "Enter x, y, r for the first circle: ";
        cin >> cir1.x;
        cin >> cir1.y;
        cin >> cir1.r;
        cout << "Enter x, y, r for the second circle: ";
        cin >> cir2.x;
        cin >> cir2.y;
        cin >> cir2.r;

        if (!CircleCheck(cir1.r) || !CircleCheck(cir2.r)) {
            cout << "Error input data" << endl;
            cin.get();
            cin.get();
        }

        cout << "\t\t1. ";
        cout << "Circle(" << cir1.x << " " << cir1.y << ", " << cir1.r << ")"
             << endl;
        cout << "Area: " << AreaCircle(cir1.r)
             << "\nPerimeter: " << PerimeterCircle(cir1.r) << endl;

        bool flag = IntersectCircle(
                cir1.x, cir1.y, cir1.r, cir2.x, cir2.y, cir2.r);
        if (flag) {
            cout << "Intersects: 2. Circle" << endl;
        } else
            cout << "Intersects: ---" << endl;

        cout << "\t\t2. ";
        cout << "Circle(" << cir2.x << " " << cir2.y << ", " << cir2.r << ")"
             << endl;
        cout << "Area: " << AreaCircle(cir2.r)
             << "\nPerimeter: " << PerimeterCircle(cir2.r) << endl;

        if (flag) {
            cout << "Intersects: 1. Circle" << endl;
        } else
            cout << "Intersects: ---" << endl;
    }

    if (f == 2 and f1 == 2) {
        cout << "Enter x, y, x1, y1, x2, y2 for the first triangle: ";
        cin >> tri1.x;
        cin >> tri1.y;
        cin >> tri1.x1;
        cin >> tri1.y1;
        cin >> tri1.x2;
        cin >> tri1.y2;
        cout << "Enter x, y, x1, y1, x2, y2 for the first triangle: ";
        cin >> tri2.x;
        cin >> tri2.y;
        cin >> tri2.x1;
        cin >> tri2.y1;
        cin >> tri2.x2;
        cin >> tri2.y2;

        if (!TriangleCheck(tri1) || !TriangleCheck(tri2)) {
            cout << "Error input data" << endl;
            cin.get();
            cin.get();
        }

        cout << "\t\t1. ";
        cout << "Triangle(" << tri1.x << " " << tri1.y << ", " << tri1.x1 << " "
             << tri1.y1 << ", " << tri1.x2 << " " << tri1.y2 << ")" << endl;
        cout << "Area: "
             << AreaTriangle(tri1.x, tri1.y, tri1.x1, tri1.y1, tri1.x2, tri1.y2)
             << "\nPerimeter: "
             << PerimeterTriangle(
                        tri1.x, tri1.y, tri1.x1, tri1.y1, tri1.x2, tri1.y2)
             << endl;

        bool flag = Intersection(tri1, tri2);
        if (flag) {
            cout << "Intersects: 2. Triangle" << endl;
        } else
            cout << "Intersects: ---" << endl;

        cout << "\t\t2. ";
        cout << "Triangle(" << tri2.x << " " << tri2.y << ", " << tri2.x1 << " "
             << tri2.y1 << ", " << tri2.x2 << " " << tri2.y2 << ")" << endl;
        cout << "Area: "
             << AreaTriangle(tri2.x, tri2.y, tri2.x1, tri2.y1, tri2.x2, tri2.y2)
             << "\nPerimeter: "
             << PerimeterTriangle(
                        tri2.x, tri2.y, tri2.x1, tri2.y1, tri2.x2, tri2.y2)
             << endl;

        if (flag) {
            cout << "Intersects: 1. Triangle" << endl;
        } else
            cout << "Intersects: ---" << endl;
    }

    if ((f == 1 and f1 == 2) or (f == 2 and f1 == 1)) {
        cout << "Enter x, y, r for the first circle: ";
        cin >> cir1.x;
        cin >> cir1.y;
        cin >> cir1.r;
        cout << "Enter x, y, x1, y1, x2, y2 for the first triangle: ";
        cin >> tri1.x;
        cin >> tri1.y;
        cin >> tri1.x1;
        cin >> tri1.y1;
        cin >> tri1.x2;
        cin >> tri1.y2;

        if (!CircleCheck(cir1.r) || !TriangleCheck(tri1)) {
            cout << "Error input data" << endl;
            cin.get();
            cin.get();
        }

        cout << "\t\t1. Circle(" << cir1.x << " " << cir1.y << ", " << cir1.r
             << ")" << endl;
        cout << "Area: " << AreaCircle(cir1.r)
             << "\nPerimeter: " << PerimeterCircle(cir1.r) << endl;

        if (TriangleAndCircleInf(tri1, cir1)) {
            cout << "Intersects: 2. Triangle" << endl;
        } else
            cout << "Intersects: ---" << endl;

        cout << "\t\t2. Triangle(" << tri1.x << " " << tri1.y << ", " << tri1.x1
             << " " << tri1.y1 << ", " << tri1.x2 << " " << tri1.y2 << ")"
             << endl;
        cout << "Area: "
             << AreaTriangle(tri1.x, tri1.y, tri1.x1, tri1.y1, tri1.x2, tri1.y2)
             << "\nPerimeter: "
             << PerimeterTriangle(
                        tri1.x, tri1.y, tri1.x1, tri1.y1, tri1.x2, tri1.y2)
             << endl;

        if (TriangleAndCircleInf(tri1, cir1)) {
            cout << "Intersects: 1. Circle" << endl;
        } else
            cout << "Intersects: ---" << endl;
    }
    cin.get();
    cin.get();
    return 0;
}