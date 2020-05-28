#include "Intersection.h"

bool Intersection(Figure tri1, Figure tri2)
{
    const double EPS = 1e-10;
    struct D_Point {
        double x;
        double y;
    };
    D_Point a[3], b[3];

    a[0].x = tri1.x;
    a[0].y = tri1.y;
    a[1].x = tri1.x1;
    a[1].y = tri1.y1;
    a[2].x = tri1.x2;
    a[2].y = tri1.y2;

    b[0].x = tri2.x;
    b[0].y = tri2.y;
    b[1].x = tri2.x1;
    b[1].y = tri2.y1;
    b[2].x = tri2.x2;
    b[2].y = tri2.y2;

    double sumf = 0;
    for (int i = 0; i < 3; ++i) {
        double det
                = a[i % 3].x * a[(i + 1) % 3].y - a[(i + 1) % 3].x * a[i % 3].y;
        sumf += det;
    }
    double sa = abs(sumf / 2);

    int flag = 0;
    for (auto i : b) {
        double sum = 0;
        for (int j = 0; j < 3; ++j) {
            D_Point c[3];
            for (int k = 0; k < 3; ++k)
                if (k == j)
                    c[k] = i;
                else
                    c[k] = a[k];

            double sumfo = 0;
            for (int k = 0; k < 3; ++k) {
                double det = c[k % 3].x * c[(k + 1) % 3].y
                        - c[(k + 1) % 3].x * c[k % 3].y;
                sumfo += det;
            }
            sum += abs(sumfo / 2);
        }

        if (abs(sa - sum) < EPS) {
            flag = 1;
            break;
        }
    }
    return flag;
}