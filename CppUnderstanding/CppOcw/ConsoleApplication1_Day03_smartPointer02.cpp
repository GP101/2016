#include <stdio.h>
#include <memory>

class KParent;
class KChild;
typedef std::shared_ptr<KParent>    ParentPtr;
typedef std::weak_ptr<KParent>      ParentWeakPtr;
typedef std::shared_ptr<KChild>     ChildPtr;

class KChild
{
public:
    ParentPtr _parent;
public:
    ~KChild()
    {
        ParentPtr sp = _parent;
        if (sp)
            printf("~KChild() %i\n", _parent.use_count());
    }
    void SetParent(ParentPtr p) { _parent = p; }
};

class KParent : std::enable_shared_from_this<KParent>
{
public:
    ChildPtr _child;
public:
    ~KParent()
    {
        if (_child)
            printf("~KParent() %i\n", _child.use_count());
    }
    void SetChild(ChildPtr p) { _child = p; }
    void CreateChild()
    {
        _child.reset(new KChild());
        //_child->SetParent(shared_from_this());
    }
};

void main()
{
    ParentPtr p;
    p.reset(new KParent());
    p->CreateChild();
    p->_child->SetParent(p);

    printf("%i\n", p.use_count());
    /** output:
        2
    */
}
