#include "PerimeterTriangle.h"

double PerimeterTriangle(
        double x, double y, double x1, double y1, double x2, double y2)
{
    double perimeter = sqrt(pow(x1 - x, 2) + pow(y1 - y, 2));
    perimeter += sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    perimeter += sqrt(pow(x - x2, 2) + pow(y - y2, 2));
    return perimeter;
}
