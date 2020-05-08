#include "circle.h"
#include <cmath>
#include <iostream>
#define P 3.14
using namespace std;

float Perimeter(int r) {
    float perimeter = 2 * 3.14 * r;
    return perimeter;
}

float Area(int r) {
    float area = 3.14 * r * r;
    return area;
}
