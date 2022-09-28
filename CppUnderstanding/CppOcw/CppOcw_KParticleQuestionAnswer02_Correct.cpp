#include <stdio.h>
#include <memory>

class KParticleManager;
class KParticle;
typedef std::shared_ptr<KParticleManager>   KParticleManagerPtr;
typedef std::weak_ptr<KParticleManager>     KParticleManagerWeakPtr;
typedef std::shared_ptr<KParticle>          KParticlePtr;
class KParticle
{
private:
    KParticleManagerWeakPtr _particleManager;
    int _data;

public:
    KParticle(KParticleManagerWeakPtr manager_, int data_)
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

class KParticleManager : std::enable_shared_from_this<KParticleManager>
{
private:
    KParticlePtr    _particles[10];
    int             _numParticle;
    int             _data;
public:
    KParticleManager()
    {
        _numParticle = 0;
        _data = 11;
        //for (int i = 0; i < _countof(_particles); ++i)
        //    _particles[i] = nullptr;
    }
    ~KParticleManager()
    {
        for (int i=0;i<_countof(_particles);++i)
        {
            _particles[i].reset();
        }
        printf("%s\n", __FUNCTION__);
    }
    //KParticlePtr CreateParticle(int d)
    //{

    //    _particles[_numParticle].reset(new KParticle(weak_from_this(), d));
    //    KParticlePtr particle = _particles[_numParticle];
    //    _numParticle += 1;
    //    return particle;
    //}
    void AddParticle(KParticlePtr p)
    {
        _particles[_numParticle] = p;
        _numParticle += 1;
    }
    KParticlePtr operator[](int index_) { return _particles[index_]; }
    int GetNumParticle() const
    {
        return _numParticle;
    }
};

void main()
{
    KParticleManagerPtr pManager;
    pManager.reset(new KParticleManager());
    KParticlePtr p1;
    KParticlePtr p2;
    p1.reset(new KParticle(pManager, 1));
    p2.reset(new KParticle(pManager, 2));
    pManager->AddParticle(p1);
    pManager->AddParticle(p2);
    for (int i = 0; i < pManager->GetNumParticle(); ++i)
    {
        KParticlePtr p = (*pManager)[i];
        printf("%i, ", p->GetData());
    }
    pManager.reset();
}
