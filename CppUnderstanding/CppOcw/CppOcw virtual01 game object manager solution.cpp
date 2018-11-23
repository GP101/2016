#include <stdio.h>
#include <vector>
#include <iostream>
#include <memory>

class KBase;
typedef std::shared_ptr<KBase>  KBasePtr;
class KBase
{
public:
    virtual void Update()
    {
        std::cout << "Base Update\r\n";
    }
    int GetUid() const
    {
        return _uid;
    }
private:
    int     _uid = 0;
};

class KMonster : public KBase
{
public:
    virtual void Update() override
    {
        std::cout << "Monster Update\r\n";
    }
};

class KCharacter : public KBase
{
public:
    virtual void Update() override
    {
        std::cout << "Character Update\r\n";
    }
};

void main()
{
    std::vector<KBasePtr>    gameObjects;
    KBasePtr    sp;
    KBasePtr    sp2;
    sp.reset( new KMonster() );
    sp2.reset( new KCharacter() );
    gameObjects.push_back( sp );
    gameObjects.push_back( sp2 );

    for (KBasePtr sp : gameObjects)
    {
        sp->Update();
    }
}
