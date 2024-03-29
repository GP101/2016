#include <stdio.h>
#include <cmath>
#include <bitset>
#include <iostream>

typedef unsigned int uint;

enum class Layer
{
    LAYER_BACKGROUND    = 0,//0b000000000001,
    LAYER_DEFAULT       = 1,//0b000000000010,
    LAYER_FOREGROUND    = 2,//0b000000000100,
    LAYER_3             = 3,//0b000000001000
};

uint ToLayerMask(enum class Layer l)
{
    return 1 << (int)l;
}

int main()
{
    uint collLayer = ToLayerMask(Layer::LAYER_BACKGROUND) | ToLayerMask(Layer::LAYER_FOREGROUND);
    std::cout << std::bitset<16>(collLayer) << std::endl;
}
