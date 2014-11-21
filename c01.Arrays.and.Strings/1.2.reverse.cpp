#include <cstring>
#include <algorithm>
#include <iostream>

/**
 * You should always check the input!!!
 * Never assume anything on the input!!!
 */
void reverse( char * str )
{
    if ( ! str )
        return;

    int len = std::strlen( str );
    for ( int i = 0, j = len - 1; i < j; ++i, --j )
        std::swap( str[ i ], str[ j ] );
}

int main()
{
    char str[] = "abcd";

    std::cout << str << std::endl;
    reverse( str );
    std::cout << str << std::endl;

    return 0;
}
