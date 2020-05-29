#include "SegmentСheck.h"

bool commonSectionCircle(
        double x1,
        double y1,
        double x2,
        double y2,
        double x,
        double y,
        double R)
{
    x1 -= x;
    y1 -= y;
    x2 -= x;
    y2 -= y;

    double dx = x2 - x1;
    double dy = y2 - y1;
    double a = dx * dx + dy * dy;
    double b = 2. * (x1 * dx + y1 * dy);
    double c = x1 * x1 + y1 * y1 - R * R;

    if (-b < 0)
        return (c < 0);
    if (-b < (2. * a))
        return ((4. * a * c - b * b) < 0);
    return (a + b + c < 0);
}