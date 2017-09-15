#include <stdio.h>
#include <tuple>

template<int...> struct seq {};

template<int max, int... s> struct make_seq : make_seq< max - 1, max - 1, s... >
{};

template<int... s> struct make_seq<0, s...>
{
    typedef seq<s...> type;
};

template<int max> using MakeSeq = typename make_seq<max>::type;

template<int x, typename Arg>
struct foo_storage
{
    Arg data;
};

template<typename Seq, typename... Args>
struct foo_helper {};

template<int s0, int... s, typename A0, typename... Args>
struct foo_helper<seq<s0, s...>, A0, Args...>
    : foo_storage<s0, A0>
    , foo_helper<seq<s...>, Args...>
{};

template<typename... Args>
struct foo : foo_helper< MakeSeq<sizeof...( Args )>, Args... >
{
};

template<int N, typename T>
T& get( foo_storage<N, T>& f )
{
    return f.data;
}

void main()
{
    foo<float, int> f;
    get<0>( f ) = 2.1f;
    get<1>( f ) = 3;
    printf( "%g\r\n", get<0>( f ) );
    printf( "%i\r\n", get<1>( f ) );
}