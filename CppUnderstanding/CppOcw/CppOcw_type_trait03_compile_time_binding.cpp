#include <iostream>

// First way of operating.
template< bool B > struct Algorithm {
    template<class T> static int do_it(T& a) {
        printf("first\r\n");
        return 0;
    }
};

// Second way of operating.
template<> struct Algorithm<true> {
    template<class T> static int do_it(T a) {
        printf("second\r\n");
        return 0;
    }
};

// Instantiating 'elaborate' will automatically instantiate the correct way to operate.
template<class T>
int elaborate(T a) {
    return Algorithm<std::is_floating_point<T>::value>::do_it(a);
}

void main() {
    elaborate(1.0f);
    elaborate(1);
}