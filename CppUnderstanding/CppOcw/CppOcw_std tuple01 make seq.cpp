#include <stdio.h>
#include <tuple>

// Url: https ://stackoverflow.com/questions/17178499/how-does-stdget-work

template<int...> struct seq {};

template<int max, int... s> struct make_seq : make_seq< max - 1, max - 1, s... >
{};

template<int... s> struct make_seq<0, s...>
{
    typedef seq<s...> type;
};

template<int max> using MakeSeq = typename make_seq<max>::type;


void main()
{
    std::tuple<float, int> f;
    std::get<0>( f ) = 2.1f;
    std::get<1>( f ) = 3;
    printf( "%g\r\n", std::get<0>( f ) );
    printf( "%i\r\n", std::get<1>( f ) );
}