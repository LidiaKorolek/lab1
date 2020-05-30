#include "TriangleCheck.h"

bool TriangleCheck(Figure tr)
{
    if ((tr.x2 - tr.x) / (tr.x1 - tr.x) == (tr.y2 - tr.y) / (tr.y1 - tr.y))
        return false;
    else
        return true;
}