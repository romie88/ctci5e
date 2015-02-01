//17.2

#include <vector>
#include <unordered_map>
#include <stdexcept>
#include <iostream>
#include <cassert>

enum class Piece {
    EMPTY,
    O,
    X,
};

std::ostream & operator << ( std::ostream & os, const Piece & p ) {
    switch( p ) {
        case Piece::EMPTY:
            os << "empty"; break;
        case Piece::O:
            os << "O"; break;
        case Piece::X:
            os << "X"; break;
        default:
            os.setstate( std::ios_base::failbit );
    }
    return os;
}

//Solution 1: try to optimize by some preprocessing

//Each cell has three status: empty, 'o', 'x'
//There are 3^9, or about 20,000 tic-tac-toe boards status (assume 3 * 3)
//We can represent our tic-tac-toe board as an int, with each digit
//representing a cell (0 means empty, 1 means 'o', 2 means 'x'). We set up
//a hash table or array in advance with all possible boards as keys
//and the value indicating who has won.

int convertBoardToInt(
        const std::vector< std::vector< Piece > > & board ) {
    
    int factor = 1;
    int sum    = 0;
    for ( const auto r : board ) {
        for ( const auto c : r ) {
            int v = 0;
            if ( c == Piece::X )
                v = 2;
            else if ( c == Piece::O )
                v = 1;
            
            sum += v * factor;
            factor *= 3;
        }
    }
    
    return sum;
}

Piece hasWon( int boardInt,
              const std::unordered_map< int, Piece > & winnerHashtable ) {
    const auto it = winnerHashtable.find( boardInt );
    if ( it != winnerHashtable.end() )
        return it->second;
    else
        throw std::out_of_range( "input board int is out of range" );
}

//If we need to convert a board into this format every time we want to
//check for a winner, we haven't saved ourselves any time compared with
//the other solutions. But, if we can store the board this way from the
//very beginning, then the lookup process will be very efficient.

//Solution 2: straightforward implementation for 3 x 3 board

Piece hasWon_3_by_3( const std::vector< std::vector< Piece > > & board ) {
    
    for ( const auto & r : board )
        assert( board.size() == r.size() );
    
    for ( std::vector< std::vector< Piece > >::size_type i = 0;
          i < board.size(); ++i ) {

        /* Check Rows */
        if ( board[ i ][ 0 ] != Piece::EMPTY
          && board[ i ][ 0 ] == board[ i ][ 1 ]
          && board[ i ][ 0 ] == board[ i ][ 2 ] )
            return board[ i ][ 0 ];

        /* Check Columns */
        if ( board[ 0 ][ i ] != Piece::EMPTY
          && board[ 0 ][ i ] == board[ 1 ][ i ]
          && board[ 0 ][ i ] == board[ 2 ][ i ] )
            return board[ 0 ][ i ];
    }

    /* Check Diagonal */
    if ( board[ 0 ][ 0 ] != Piece::EMPTY
      && board[ 0 ][ 0 ] == board[ 1 ][ 1 ]
      && board[ 0 ][ 0 ] == board[ 2 ][ 2 ] )
        return board[ 0 ][ 0 ];

    /* Check Reverse Diagonal */
    if ( board[ 0 ][ 2 ] != Piece::EMPTY
      && board[ 0 ][ 2 ] == board[ 1 ][ 1 ]
      && board[ 0 ][ 2 ] == board[ 2 ][ 0 ] )
        return board[ 0 ][ 2 ];

    return Piece::EMPTY;
}

//Solution 3: N x N board
Piece hasWon_n_by_n( const std::vector< std::vector< Piece > > & board ) {

    for ( const auto & r : board )
        assert( board.size() == r.size() );
    
    for ( std::vector< std::vector< Piece > >::size_type i = 0;
          i < board.size(); ++i ) {

        /* Check Rows */
        if ( board[ i ][ 0 ] != Piece::EMPTY ) {
            std::vector< Piece >::size_type j = 1;
            for ( ; j < board[ i ].size(); ++j ) {
                if ( board[ i ][ 0 ] != board[ i ][ j ] )
                    break;
            }
            if ( j == board[ i ].size() )
                return board[ i ][ 0 ];
        }
        
        /* Check Columns */
        if ( board[ 0 ][ i ] != Piece::EMPTY ) {
            std::vector< std::vector< Piece > >::size_type j = 1;
            for ( ; j < board.size(); ++j ) {
                if ( board[ 0 ][ i ] != board[ j ][ i ] )
                    break;
            }
            if ( j == board.size() )
                return board[ 0 ][ i ];
        }
    }
    
    /* Check Diagonal */
    if ( board[ 0 ][ 0 ] != Piece::EMPTY ) {
        std::vector< Piece >::size_type i = 1;
        for ( ; i < board[ 0 ].size(); ++i ) {
            if ( board[ 0 ][ 0 ] != board[ i ][ i ] )
                break;
        }
        if ( i == board[ 0 ].size() )
            return board[ 0 ][ 0 ];
    }
    
    /* Check Reverse Diagonal */
    if ( board[ 0 ][ board[ 0 ].size() - 1 ] != Piece::EMPTY ) {
        std::vector< Piece >::size_type i = 1;
        for ( ; i < board[ 0 ].size(); ++i ) {
            if ( board[ 0 ][ board[ 0 ].size() - 1 ]
              != board[ i ][ board[ 0 ].size() - 1 - i ] )
                break;
        }
        if ( i == board[ 0 ].size() )
            return board[ 0 ][ board[ 0 ].size() - 1 ];
    }
    
    return Piece::EMPTY;   
}

//Solution 4: shorter
Piece hasWon_n_by_n_shorter(
        const std::vector< std::vector< Piece > > & board ) {
    
    for ( const auto & r : board )
        assert( board.size() == r.size() );
    
    Piece ps[] = { Piece::O, Piece::X };
    for ( const auto p : ps ) {
        
        /* Check Rows and Columns */
        std::vector< Piece >::size_type i, j;
        const std::vector< Piece >::size_type
            N = board.size();
        for ( i = 0; i < N; ++i ) {
            bool maybe_row    = true;
            bool maybe_column = true;
            for ( j = 0; j < N; ++j ) {
                if ( p != board[ i ][ j ] )//row
                    maybe_row = false;
                if ( p != board[ j ][ i ] )//column
                    maybe_column = false;
            }
            if ( maybe_row || maybe_column )
                return p;
        }

        /* Check both diagonals */
        bool maybe_diag1 = true;
        bool maybe_diag2 = true;
        for ( i = 0; i < N; ++i ) {
            if ( p != board[ i ][ i ] )
                maybe_diag1 = false;
            if ( p != board[ i ][ N - 1 - i ] )
                maybe_diag2 = false;
        }
        if ( maybe_diag1 || maybe_diag2 )
            return p;
    }

    return Piece::EMPTY;
}

//Solution 5: prioritizes code reuse
enum class Check {
    ROW,
    COLUMN,
    DIAGONAL,
    REVERSE_DIAGONAL,
};

Piece get_piece(
    const std::vector< std::vector< Piece > > & board,
    int i1,
    int i2,
    const Check check ) {

    const std::vector< Piece >::size_type N = board[ 0 ].size();
    switch ( check ) {
        case Check::ROW:
            return board[ i1 ][ i2 ];
        case Check::COLUMN:
            return board[ i2 ][ i1 ];
        case Check::DIAGONAL:
            return board[ i2 ][ i2 ];
        case Check::REVERSE_DIAGONAL:
            return board[ N - 1 - i2 ][ i2 ];
        default:
            return Piece::EMPTY;
    }
}

Piece get_winner(
    const std::vector< std::vector< Piece > > & board,
    int fixed_i,
    const Check check ) {
    
    Piece p = get_piece( board, fixed_i, 0, check );
    if ( p == Piece::EMPTY )
        return p;

    for ( std::vector< Piece >::size_type i = 1;
          i < board.size(); ++i ) {
        if ( p != get_piece( board, fixed_i, i, check ) )
            return Piece::EMPTY;
    }
    return p;
}

Piece hasWon_code_reuse(
    const std::vector< std::vector< Piece > > & board ) {
    
    for ( const auto & r : board )
        assert( board.size() == r.size() );
    
    Piece winner = Piece::EMPTY;

    /* Check Rows and Columns */
    std::vector< Piece >::size_type i;
    const std::vector< Piece >::size_type N = board.size();
    for ( i = 0; i < N; ++i ) {
        winner = get_winner( board, i, Check::ROW );
        if ( winner != Piece::EMPTY )
            return winner;
        
        winner = get_winner( board, i, Check::COLUMN );
        if ( winner != Piece::EMPTY )
            return winner;
    }

    winner = get_winner( board, -1, Check::DIAGONAL );
    if ( winner != Piece::EMPTY )
        return winner;

    winner = get_winner( board, -1, Check::REVERSE_DIAGONAL );
    if ( winner != Piece::EMPTY )
        return winner;

    return Piece::EMPTY;
}

int main() {
    
    {
        std::vector< std::vector< Piece > >
            board = {
                { Piece::X,     Piece::O, Piece::X },
                { Piece::EMPTY, Piece::X, Piece::O },
                { Piece::X,     Piece::X, Piece::O },
            };

        int v = convertBoardToInt( board );
        std::cout << v << std::endl;
        
        Piece p = hasWon_3_by_3( board );
        std::cout << p << std::endl;

        p = hasWon_n_by_n( board );
        std::cout << p << std::endl;

        p = hasWon_n_by_n_shorter( board );
        std::cout << p << std::endl;

        p = hasWon_code_reuse( board );
        std::cout << p << std::endl;
    }
    
    return 0;
}
