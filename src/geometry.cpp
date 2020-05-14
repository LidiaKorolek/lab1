#include <iostream>
#include <math.h>

#define Pi 3.14

using namespace std;

double PerimeterCircle(double r) {
    float perimeter = 2 * Pi * r;
    return perimeter;
}

double AreaCircle(double r) {
    float area = Pi * r * r;
    return area;
}

double PerimeterTriangle(double x, double y, double x1, double y1, double x2, double y2) {
    double perimeter = sqrt(pow(x1 - x, 2) + pow(y1 - y, 2));
    perimeter += sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    perimeter += sqrt(pow(x - x2, 2) + pow(y - y2, 2));
    return perimeter;
}

double AreaTriangle(double x, double y, double x1, double y1, double x2, double y2) {
    double S = abs((x1 - x) * (y2 - y) - (x2 - x) * (y1 - y));
    return S;
}

int main() {
    cout << "Choose two figures: 1.Circle 2.Triangle" << endl;
    int f, f1;
    cin >> f >> f1;
    struct Figure {
        double x, y, x1, y1, x2, y2, r;
    };

    Figure cir1;
    Figure tri1;
    Figure cir2;
    Figure tri2;

    if (f1 <= 0 || f <= 0 || f1 > 2 || f > 2) {
        cout << "Error input data" << endl;
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

        cout << "\t\t1. ";
        cout << "Circle(" << cir1.x << " " << cir1.y << ", " << cir1.r << ")" << endl;
        cout << "Area: " << AreaCircle(cir1.r) << "\nPerimeter: " << PerimeterCircle(cir1.r) << endl;

        cout << "\t\t2. ";
        cout << "Circle(" << cir2.x << " " << cir2.y << ", " << cir2.r << ")" << endl;
        cout << "Area: " << AreaCircle(cir2.r) << "\nPerimeter: " << PerimeterCircle(cir2.r) << endl;
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

        cout << "\t\t1. ";
        cout << "Triangle(" << tri1.x << " " << tri1.y << ", " << tri1.x1 << " "
             << tri1.y1 << ", " << tri1.x2 << " " << tri1.y2 << ")" << endl;
        cout << "Area: "
             << AreaTriangle(tri1.x, tri1.y, tri1.x1, tri1.y1, tri1.x2, tri1.y2)
             << "\nPerimeter: " << PerimeterTriangle(tri1.x,
                                                     tri1.y, tri1.x1, tri1.y1, tri1.x2, tri1.y2) << endl;

        cout << "\t\t2. ";
        cout << "Triangle(" << tri2.x << " " << tri2.y << ", " << tri2.x1 << " "
             << tri2.y1 << ", " << tri2.x2 << " " << tri2.y2 << ")" << endl;
        cout << "Area: "
             << AreaTriangle(tri2.x, tri2.y, tri2.x1, tri2.y1, tri2.x2, tri2.y2)
             << "\nPerimeter: " << PerimeterTriangle(tri2.x,
                                                     tri2.y, tri2.x1, tri2.y1, tri2.x2, tri2.y2) << endl;
        return 0;
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

        cout << "\t\t1. Circle(" << cir1.x << " " << cir1.y << ", " << cir1.r
             << ")" << endl;
        cout << "Area: " << AreaCircle(cir1.r) << "\nPerimeter: "
             << PerimeterCircle(cir1.r) << endl;

        cout << "\t\t2. Triangle(" << tri1.x << " " << tri1.y << ", "
             << tri1.x1 << " " << tri1.y1 << ", " << tri1.x2 << " " << tri1.y2
             << ")" << endl;
        cout << "Area: "
             << AreaTriangle(tri1.x, tri1.y, tri1.x1, tri1.y1, tri1.x2, tri1.y2)
             << "\nPerimeter: " << PerimeterTriangle(tri1.x,
                                                     tri1.y, tri1.x1, tri1.y1, tri1.x2, tri1.y2) << endl;
    }

}