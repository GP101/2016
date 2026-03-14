#include <stdio.h>
#include <memory>

struct KPacket;
typedef KPacket* KPacketPtr;
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
        ipRef = nullptr;
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
        ipRef = nullptr;
    }
};

void main()
{
    KPacketPtr spPacket;
    spPacket = new KPacket();
    spPacket->m_data = 3;

    KUser   t;
    t.SetPacket(spPacket);
    t.GetPacket().Print();
    delete spPacket;
    spPacket = nullptr;

    if (t.IsSafeData())
        t.GetPacket().Print(); // dangling pointer
}
