#pragma once
#include <cmath>

class KQuaternion
{
public:
    const static KQuaternion Zero;
    const static KQuaternion  One;
    const static KQuaternion iHat;
    const static KQuaternion jHat;
    const static KQuaternion kHat;

public:
    double w;
    double x;
    double y;
    double z;

public: // Constructors
    KQuaternion( );
    KQuaternion( const KQuaternion& Q );
    KQuaternion( const double w0, const double x0, const double y0, const double z0 );

    KQuaternion operator/( const double t ) const { return KQuaternion( w / t, x / t, y / t, z / t ); }
    KQuaternion operator*( const KQuaternion& Q ) const;
    KQuaternion operator/( const KQuaternion& Q ) const { return ( *this )*( Q.inverse( ) ); }

    KQuaternion inverse( ) const { return conjugate( ) / normsquared( ); }
    KQuaternion conjugate( ) const { return KQuaternion( w, -x, -y, -z ); }
    double      normsquared( ) const { return ( w*w + x*x + y*y + z*z ); }

    KQuaternion& operator=(const KQuaternion& Q) { w = Q.w; x = Q.x; y = Q.y; z = Q.z; return *this; }
    KQuaternion& operator+=(const KQuaternion& Q) { w += Q.w; x += Q.x; y += Q.y; z += Q.z; return *this; }
    bool        operator!=(const KQuaternion& Q) const { if (w != Q.w) return false; if (x != Q.x) return false; if (y != Q.y) return false; if (z != Q.z) return false; return true; }
    bool        operator==(const KQuaternion& Q) const { return !((*this) != Q); }
    KQuaternion operator-() const { return KQuaternion(-w, -x, -y, -z); }
    KQuaternion operator+(const double t) const { return KQuaternion(w + t, x, y, z); }
    KQuaternion operator-(const double t) const { return KQuaternion(w - t, x, y, z); }
    KQuaternion operator*(const double t) const { return KQuaternion(w * t, x * t, y * t, z * t); }
    //KQuaternion operator/(const double t) const { return KQuaternion(w / t, x / t, y / t, z / t); }
    KQuaternion operator+(const KQuaternion& Q) const { return KQuaternion(w + Q.w, x + Q.x, y + Q.y, z + Q.z); }
    KQuaternion operator-(const KQuaternion& Q) const { return KQuaternion(w - Q.w, x - Q.x, y - Q.y, z - Q.z); }
};

KQuaternion operator+(const double t, const KQuaternion& Q);
KQuaternion operator-(const double t, const KQuaternion& Q);
KQuaternion operator*(const double t, const KQuaternion& Q);
