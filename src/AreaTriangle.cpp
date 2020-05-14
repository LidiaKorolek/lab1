#include "AreaTriangle.h"

double AreaTriangle(double x, double y, double x1, double y1, double x2, double y2) {
    double S = abs((x1 - x) * (y2 - y) - (x2 - x) * (y1 - y));
    return S;
}
