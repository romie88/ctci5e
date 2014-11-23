#include <vector>
#include <iostream>

void zero_out_matrix( std::vector< std::vector< int > > & m )
{
    if ( m.size() == 0 )
        return;

    std::vector< std::vector< int > >::size_type ROWS = m.size();
    std::vector< int >::size_type                COLS = m[ 0 ].size();

    std::vector< bool > zero_rows( ROWS, false );
    std::vector< bool > zero_cols( COLS, false );

    for ( std::vector< std::vector< int > >::size_type i = 0; i < m.size(); ++i )
    {
        for ( std::vector< int >::size_type j = 0; j < m[ i ].size(); ++j )
        {
            if ( m[ i ][ j ] == 0 )
            {
                zero_rows[ i ] = true;
                zero_cols[ j ] = true;
            }
        }
    }
    
    for ( std::vector< std::vector< int > >::size_type i = 0; i < m.size(); ++i )
    {
        for ( std::vector< int >::size_type j = 0; j < m[ i ].size(); ++j )
        {
            if ( zero_rows[ i ] || zero_cols[ j ] )
            {
                m[ i ][ j ] = 0;
            }
        }
    }
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

int main()
{
    std::vector< std::vector< int > > m = {
        { 1, 2, 0, 4 },
        { 5, 6, 7, 8 },
        { 9, 0, 11, 12 }
    };

    print_matrix( m );
    zero_out_matrix( m );
    print_matrix( m );
    
    return 0;
}
