#pragma once

template<typename T>
class KGlobalSingleton
{
public:
    typedef T           Type;
    inline static Type& Singleton() { return KSingletonCreator::Access(); }
    inline              KGlobalSingleton() {}

private:
                        KGlobalSingleton( const KGlobalSingleton& );
                        KGlobalSingleton& operator=( const KGlobalSingleton& );

protected:
    class KSingletonCreator
    {
    public:
        inline KSingletonCreator()
        {
            Access();
        }//KSingletonCreator()

        __declspec(noinline) static Type& Access( )
        {
            static Type ref;
            return ref;
        }//Access()
    };//struct KSingletonCreator

private:
    static KSingletonCreator    ms_kSingletonCreator;
};//template<typename T>

template <typename T>
/*static*/ typename KGlobalSingleton<T>::KSingletonCreator  KGlobalSingleton<T>::ms_kSingletonCreator;
