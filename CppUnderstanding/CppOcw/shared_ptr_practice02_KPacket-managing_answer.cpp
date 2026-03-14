#include <stdio.h>
#include <memory>

struct KPacket;
typedef std::shared_ptr<KPacket> KPacketPtr;
struct KPacket
{
    int m_data;
    void Print() {
        printf("data = %i\n", m_data);
    }
};

class KUser
{
private:
    KPacketPtr ipRef;
public:
    KUser()
    {
        //ipRef = nullptr;
    }
    void SetPacket(KPacketPtr ip)
    {
        ipRef = ip;
    }
    KPacket GetPacket() const
    {
        return *ipRef;
    }
    bool IsSafeData() const
    {
        if (ipRef)
            return true;
        return false;
    }
    void Release()
    {
        ipRef.reset();
    }
};

void main()
{
    KPacketPtr spPacket;
    spPacket.reset(new KPacket());
    spPacket->m_data = 3;

    KUser   t;
    t.SetPacket(spPacket);
    t.GetPacket().Print();
    //delete ip;
    //ip = nullptr;
    spPacket.reset();

    if (t.IsSafeData())
        t.GetPacket().Print();
    t.Release();
    if (t.IsSafeData())
        t.GetPacket().Print();
}
