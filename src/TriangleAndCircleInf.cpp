#include "TriangleAndCircleInf.h"

bool TriangleAndCircleInf(Figure tri1, Figure cir1)
{
    if (SegmentCheck(tri1.x, tri1.y, tri1.x1, tri1.y1, cir1.x, cir1.y, cir1.r))
        return true;
    if (SegmentCheck(
                tri1.x1, tri1.y1, tri1.x2, tri1.y2, cir1.x, cir1.y, cir1.r))
        return true;
    if (SegmentCheck(tri1.x2, tri1.y2, tri1.x, tri1.y, cir1.x, cir1.y, cir1.r))
        return true;
    else
        return false;
}