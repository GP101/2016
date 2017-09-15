#include <stdio.h>

class KTire
{
public:
    float radius;
};

class KCar
{
public:
    void Move()
    {
        printf( "KCar::Move()\r\n" );
    }
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
    KSportCar() : wing( nullptr ), driver( nullptr ) {}
    ~KSportCar()
    {
        delete wing;
    }
    void Move() // override
    {
        KCar::Move();
        printf( "KSportCar::Move()\r\n" );
    }
    void Turbo() {}
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
    //KSportCar   car;
    //car.Move();
    //KCar        car2;
    //car2.Move();

    KCar*  pCar = new KSportCar;
    pCar->Move();
    delete pCar;
}