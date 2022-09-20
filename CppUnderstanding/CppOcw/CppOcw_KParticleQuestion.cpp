#include <stdio.h>

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
    int GetData() const
    {
        return _data;
    }
};

class KParticleManager
{
private:
    KParticle*      _particles[10];
    int             _numParticle;
    int             _data;
public:
    KParticleManager()
    {
        _numParticle = 0;
        _data = 11;
    }
    KParticle* CreateParticle(int d)
    {

        _particles[_numParticle] = new KParticle(this, d);
        KParticle* particle = _particles[_numParticle];
        _numParticle += 1;
        return particle;
    }
    KParticle* operator[](int index_) { return _particles[index_]; }
    int GetNumParticle() const
    {
        return _numParticle;
    }
};

void main()
{
    KParticleManager manager;
    manager.CreateParticle(1);
    manager.CreateParticle(2);
    for (int i = 0; i < manager.GetNumParticle(); ++i)
    {
        KParticle* p = manager[i];
        printf("%i, ", p->GetData());
    }
}
