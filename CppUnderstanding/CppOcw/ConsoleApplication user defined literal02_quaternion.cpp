#include <iostream>
#include <iomanip>
//#include <complex>
//#include <cmath>
#include "KQuaternion.h"

#pragma warning (disable:4455)

// used as conversion
KQuaternion operator"" _i(long double r)
{
    return KQuaternion::iHat * r;
}

KQuaternion operator"" _j(long double r)
{
    return KQuaternion::jHat * r;
}

KQuaternion operator"" _k(long double r)
{
    return KQuaternion::kHat * r;
}

KQuaternion operator"" ii(long double r)
{
    return KQuaternion(-1, 0, 0, 0);
}

KQuaternion operator"" jj(long double r)
{
    return KQuaternion(-1, 0, 0, 0);
}

KQuaternion operator"" kk(long double r)
{
    return KQuaternion(-1, 0, 0, 0);
}

KQuaternion operator"" ij(long double r)
{
    return KQuaternion::kHat * r;
}

KQuaternion operator"" ik(long double r)
{
    return -KQuaternion::jHat * r;
}

KQuaternion operator"" ji(long double r)
{
    return -KQuaternion::kHat * r;
}

KQuaternion operator"" jk(long double r)
{
    return KQuaternion::iHat * r;
}

KQuaternion operator"" ki(long double r)
{
    return KQuaternion::jHat * r;
}

KQuaternion operator"" kj(long double r)
{
    return -KQuaternion::iHat * r;
}

void Print(const KQuaternion& q)
{
    printf("(%g,%g,%g,%g)\n", q.w, q.x, q.y, q.z);
}

int main()
{
    double x1 = 1.0, y1 = 2.0, z1 = 3.0;
    double x2 = 4.0, y2 = 5.0, z2 = 6.0;
    KQuaternion q1{ 0,x1,y1,z1 };
    KQuaternion q2{ 0,x2,y2,z2 };
    Print(q1 * q2);
    KQuaternion q = x1 * x2 * 1.0ii + x1 * y2 * 1.0ij + x1 * z2 * 1.0ik
        + y1 * x2 * 1.0ji + y1 * y2 * 1.0jj + y1 * z2 * 1.0jk
        + z1 * x2 * 1.0ki + z1 * y2 * 1.0kj + z1 * z2 * 1.0kk;
    Print(q1 * q2);
}
