#include <stdio.h>
#include <stdint.h>

template <uint64_t V>
constexpr uint64_t make_binary() {
    return V;
}

template <uint64_t V, char C, char... Cs>
constexpr uint64_t make_binary() {
    static_assert(C == '0' || C == '1', "invalid binary");

    return make_binary<2 * V + C - '0', Cs...>();
}

template <char... Cs>
uint64_t operator "" _b()
{
    static_assert(sizeof...(Cs) <= 64, "overflow");

    return make_binary<0, Cs...>();
}

void main()
{
    uint64_t a = 101_b; // OK: a == 5
    //uint64_t b = 102_b; // error: invalid
    //uint64_t c = 11111111110000000000111111111100000000001111111111000000000011111111110000000000_b; // error: overflow
}
