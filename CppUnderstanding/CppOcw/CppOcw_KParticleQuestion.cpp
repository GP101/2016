#include <stdio.h>
#include <algorithm>

class KParticleManager;
class KParticle
{
private:
    KParticleManager* _particleManager;
    int _data;

public:
    KParticle(KParticleManager* manager_, int data_)
    {
        _particleManager = manager_;
        _data = data_;
    }
    ~KParticle()
    {
        printf("%s\n", __FUNCTION__);
    }
    int GetData() const
    {
        return _data;
    }
};

class KParticleManager
{
private:
    KParticle* _particles[10];
    int             _numParticle;
    int             _data;
public:
    KParticleManager()
    {
        _numParticle = 0;
        _data = 11;
        for (int i = 0; i < _countof(_particles); ++i)
            _particles[i] = nullptr;
    }
    ~KParticleManager()
    {
        for (KParticle* p : _particles)
        {
            if (p != nullptr)
                delete p;
        }
        printf("%s\n", __FUNCTION__);
    }
    //KParticle* CreateParticle(int d)
    //{

    //    _particles[_numParticle] = new KParticle(this, d);
    //    KParticle* particle = _particles[_numParticle];
    //    _numParticle += 1;
    //    return particle;
    //}
    void AddParticle(KParticle* p)
    {
        _particles[_numParticle] = p;
        _numParticle += 1;
    }
    KParticle* operator[](int index_) { return _particles[index_]; }
    int GetNumParticle() const
    {
        return _numParticle;
    }
};

void main()
{
    KParticleManager* pManager = new KParticleManager();
    KParticle* p1 = new KParticle(pManager, 1);
    KParticle* p2 = new KParticle(pManager, 1);
    pManager->AddParticle(p1);
    pManager->AddParticle(p2);
    for (int i = 0; i < pManager->GetNumParticle(); ++i)
    {
        KParticle* p = (*pManager)[i];
        printf("%i, ", p->GetData());
    }
    delete pManager;
}
