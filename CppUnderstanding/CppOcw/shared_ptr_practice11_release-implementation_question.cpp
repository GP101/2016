#include <stdio.h>
#include <algorithm>

template<typename T>
struct shared_ptr_traits
{
    typedef T& reference;
};

template<>
struct shared_ptr_traits<void>
{
    typedef void   reference;
};

template<typename T>
class shared_ptr
{
public:
    typedef shared_ptr<T>   this_type;
    typedef T               value_type;
    typedef T* pointer;
    typedef typename shared_ptr_traits<T>::reference
        reference;
private:
    T* px;
    int* pn;
public:
    shared_ptr(T* p = nullptr) : px(p), pn(nullptr) {
        if (px != nullptr) {
            pn = new int;
            *pn = 1;
        }//if
    }
    shared_ptr(const shared_ptr<T>& rhs) {
        px = rhs.px;
        pn = rhs.pn;
        if (px != nullptr) {
            *pn += 1;
        }
    }
    ~shared_ptr() {
        release();
    }
    void release() {
        if (px != nullptr && *pn >= 1) {
            // practice: implement release()
            // decrease reference counter
            // delete px and pn if *pn == 0
        }
        px = nullptr;
        pn = nullptr;
    }
    void swap(shared_ptr<T>& rhs) {
        std::swap(px, rhs.px);
        std::swap(pn, rhs.pn);
    }
    shared_ptr<T>& operator=(const shared_ptr<T>& rhs) {
        release();
        px = rhs.px;
        pn = rhs.pn;
        if( px != nullptr ) {
            *pn += 1;
        }
        //this_type(rhs).swap(*this); // copy-and-swap idiom
        return *this;
    }
    void reset(T* p = nullptr) {
        release();
        px = p;
        pn = nullptr;
        if( px != nullptr ) {
            pn = new int;
            *pn = 1;
        }
        //this_type(p).swap(*this);
    }
    int use_count() const {
        return *pn;
    }
};//class shared_ptr

class KTest
{
public:
    void Print() {
        printf("%s\n", __FUNCSIG__);
    }
};

void main()
{
    shared_ptr<KTest> spTest;
    spTest.reset(new KTest());
    //spTest->Print();
    printf("%i\n", spTest.use_count());
}//int main()
