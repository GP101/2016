#include <stdio.h>

class KTire
{
public:
    float radius;
};

class KCar
{
public:
    void Move() {}
private:
    KTire   tire[ 4 ];
};

class KWing
{
public:
};

class KDriver
{
};

class KSportCar : public KCar
{
public:
    KSportCar() : wing( nullptr ), driver(nullptr) {}
    ~KSportCar()
    {
        delete wing;
    }
    void Turbo() { Move(); }
    void SetDriver( KDriver* pDriver )
    {
        driver = pDriver;
    }
    void CreateAccessories()
    {
        wing = new KWing;
    }
private:
    KWing*      wing; // aggregation
    KDriver*    driver; // association
};

void main()
{
    KDriver*    pDriver = new KDriver();
    KSportCar   car;
    car.SetDriver( pDriver );
    car.Move();
    car.Turbo();

    delete pDriver;
}