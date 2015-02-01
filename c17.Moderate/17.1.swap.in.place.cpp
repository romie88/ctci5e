//17.1

#include <limits>
#include <iostream>

void swap_by_diff( int & a, int & b ) {

    //CAUTIOUS: OVERFLOW but I am surprised that it works!!!
    a = a - b;//a' = a - b;
    b = a + b;//b' = a' + b = a - b + b = a
    a = b - a;//a'' = b' - a' = a - ( a - b ) = b
}

void swap_by_xor( int & a, int & b ) {
    
    a = a ^ b;//a' = a ^ b;
    b = a ^ b;//b' = a' ^ b = a ^ b ^ b = a ^ 0 = a
    a = a ^ b;//a'' = a' ^ b' = a ^ b ^ a = 0 ^ b = b
}

int main() {

    {
        int a = 1672;
        int b = 9332;

        std::cout << "a = " << a << " b = " << b << std::endl;
        swap_by_diff( a, b );
        std::cout << "a = " << a << " b = " << b << std::endl;
        swap_by_xor( a, b );
        std::cout << "a = " << a << " b = " << b << std::endl;

        std::cout << std::endl;
    }
    
    {
        int a = std::numeric_limits< int >::max();
        int b = std::numeric_limits< int >::min();

        std::cout << "a = " << a << " b = " << b << std::endl;
        swap_by_diff( a, b );
        std::cout << "a = " << a << " b = " << b << std::endl;

        std::cout << std::endl;
    }
    
    {
        int a = std::numeric_limits< int >::max();
        int b = std::numeric_limits< int >::min();

        std::cout << "a = " << a << " b = " << b << std::endl;
        swap_by_xor( a, b );
        std::cout << "a = " << a << " b = " << b << std::endl;

        std::cout << std::endl;
    }

    return 0;
}
