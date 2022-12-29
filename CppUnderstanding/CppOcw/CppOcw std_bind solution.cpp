#pragma once
#include <stdio.h>
#include <memory>
#include <vector>
#include <queue>
#include <functional> // bind2nd
#include <algorithm> // countif, less
#include <Windows.h>

using namespace std::placeholders;// ::_1;

#define CONSTRUCTOR

class KPacket;
typedef std::shared_ptr<KPacket>  KPacketPtr;
class KPacket
{
public:
    KPacket(unsigned short id) : m_usPacketId(id) {}
    ~KPacket() {}
    KPacket& operator=(const KPacket& right) { return *this; }

public:
    LONGLONG                m_nSenderUid;
    unsigned short          m_usPacketId;
    std::vector<char>       m_buffer;

protected:
    static const wchar_t* ms_szPacketId[];
};//class KPacket


class KWorkQueue
{
public:
    KWorkQueue() {}
    virtual             ~KWorkQueue() {}

    virtual bool        Initialize(DWORD dwParam_) { return false; }
    virtual void        Finalize()
    {
    }
    void                QueueingPacket(const KPacketPtr& spPacket_)
                        {
                            m_queuePacket.push(spPacket_);
                        }
    size_t              GetQueueSize()
                        {
                            return m_queuePacket.size();
                        }

    bool                GetKPacket(KPacketPtr& spPacket_)
                        {
                            if (m_queuePacket.empty()) return false;

                            spPacket_ = m_queuePacket.front();
                            m_queuePacket.pop();
                            return true;
                        }

    template<typename Func>
    void                ProcessPackets(const Func& functor) // process all packets
                        {
                            // consume packet queue
                            KPacketPtr spPacket;

                            while (GetKPacket(spPacket)) {
                                if (spPacket != NULL) {
                                    functor(spPacket.get());  // call packet handler
                                }
                            }
                        }

protected:
    CRITICAL_SECTION        m_csPacketQueue;
    std::queue<KPacketPtr>  m_queuePacket;
};

class KSession
{
public:
    CONSTRUCTOR         KSession() {}
    virtual             ~KSession() {}

    virtual bool        Initialize(DWORD dwParam_) { return true; }
    virtual void        Finalize() {}

    virtual void        Update(DWORD dwElapsedTime_) {}
    virtual void        OnPacket(IN KPacket* pkPacket)
                        {
                            printf("%s %i\n",__FUNCTION__, pkPacket->m_usPacketId);
                        }

    void                QueueingPacket(const KPacketPtr& spPacket)
                        {
                            m_workQueue.QueueingPacket(spPacket);
                        }

    virtual void        OnDestroy()
                        {
                            // process pending packets.
                            if (m_workQueue.GetQueueSize() > 0)
                                m_workQueue.ProcessPackets(std::bind(&KSession::OnPacket, this, _1));
                        }

protected:
    KWorkQueue          m_workQueue;
};

void main()
{
    KPacketPtr packet0, packet1;
    packet0.reset(new KPacket(1));
    packet1.reset(new KPacket(2));
    KSession    session;
    session.QueueingPacket(packet0);
    session.QueueingPacket(packet1);
    session.OnDestroy();
}