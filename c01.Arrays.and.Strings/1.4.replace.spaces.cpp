#include <iostream>

void replace_spaces( char * s, int n )
{
    char * p = s;
    int num_of_spaces = 0;
    int len = 0;
    for ( char * p = s; *p; ++p )
    {
        ++len;
        if ( *p == ' ' )
            ++num_of_spaces;
    }
    
    int new_len = len + 2 * num_of_spaces;
    if ( new_len > n )
        return;

    s[ new_len ] = 0;
    for ( int i = len - 1, j = new_len - 1; i >= 0; --i )
    {
        if ( s[ i ] != ' ' )
        {
            s[ j-- ] = s[ i ];
        }
        else
        {
            s[ j-- ] = '0';
            s[ j-- ] = '2';
            s[ j-- ] = '%';
        }
    }
}

int main()
{
    char s[] = { 'M', 'r', ' ', 'J', 'o', 'h', 'n', ' ', 'S', 'm', 'i', 't', 'h', 0, 0, 0, 0, 0 };
    std::cout << s << std::endl;
    replace_spaces( s, sizeof( s ) / sizeof( s[ 0 ] ) );
    std::cout << s << std::endl;

    return 0;
}
