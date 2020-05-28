#include "IntersectCircle.h"

bool IntersectCircle(
        double x, double y, double r, double x1, double y1, double r1)
{
    bool flag = false;
    double N;
    N = sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
    if (x == x1 && y == y1 && r == r1) {
        flag = true;
    } else if (x == x1 && y == y1 && (r < r1 || r > r1)) {
        flag = false;
    } else if (N == (r + r1)) {
        flag = true;
    } else if (N <= (r + r1)) {
        flag = true;
    }
    return flag;
}