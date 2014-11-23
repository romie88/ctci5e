#include <vector>
#include <algorithm>
#include <iostream>

using Row = std::vector< std::vector< int > >::size_type;
using Col = std::vector< int >::size_type;

void transpose_matrix( std::vector< std::vector< int > > & m )
{
    if ( m.size() == 0 )
        return;

    Row ROWS = m.size();
    Col COLS = m[ 0 ].size();
    for ( Row i = 0; i < ROWS; ++i )
    {
        for ( Col j = i + 1; j < COLS; ++j )
        {
            std::swap( m[ i ][ j ], m[ j ][ i ] );
        }
    }
}

void horizontally_flip_matrix( std::vector< std::vector< int > > & m )
{
    if ( m.size() == 0 )
        return;

    Row ROWS = m.size();
    Col COLS = m[ 0 ].size();
    for ( Row i = 0; i < ROWS; ++i )
        for ( Col j1 = 0, j2 = COLS - 1; j1 < j2; ++j1, --j2 )
            std::swap( m[ i ][ j1 ], m[ i ][ j2  ] );
}

void rotate_matrix( std::vector< std::vector< int > > & m )
{
    if ( m.size() == 0 )
        return;

    transpose_matrix( m );
    horizontally_flip_matrix( m );
}

void print_matrix( std::vector< std::vector< int > > & m )
{
    for ( const auto & r : m )
    {
        for ( const auto & c : r )
            std::cout << c << ' ';

        std::cout << std::endl;
    }
}

void rotate_matrix_directly( std::vector< std::vector< int > > & m )
{
    if ( m.size() == 0 )
        return;

    Row N = m.size();
    
    for ( unsigned layer = 0; layer < N / 2; ++layer )
    {
        unsigned first = layer;
        unsigned last = N - 1 - layer;
        for ( unsigned i = first; i < last; ++i )
        {
            int offset = i - first;

            //save top
            int tmp = m[ first ][ i ];

            //left -> top
            m[ first ][ i ] = m[ last - offset ][ first ];

            //bottom -> left
            m[ last - offset ][ first ] = m[ last ][ last - offset ];

            //right -> bottom
            m[ last ][ last - offset ] = m[ i ][ last ];

            //top -> right
            m[ i ][ last ] = tmp;
        }
    }
}

int main()
{
    std::vector< std::vector< int > > m1 = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };

    print_matrix( m1 );
    rotate_matrix( m1 );
    std::cout << "after rotate clockwise 90 degrees: " << std::endl;
    print_matrix( m1 );
    rotate_matrix_directly( m1 );
    std::cout << "after rotate clockwise 90 degrees: " << std::endl;
    print_matrix( m1 );
    
    std::vector< std::vector< int > > m2 = {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 },
        { 13, 14, 15, 16 }
    };

    print_matrix( m2 );
    rotate_matrix( m2 );
    std::cout << "after rotate clockwise 90 degrees: " << std::endl;
    print_matrix( m2 );
    rotate_matrix_directly( m2 );
    std::cout << "after rotate clockwise 90 degrees: " << std::endl;
    print_matrix( m2 );

    return 0;
}
