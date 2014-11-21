#include <unordered_map>
#include <string>
#include <iostream>
#include <algorithm>

/**
 * You need to confirm the details with the interviewer!!!
 * If the anagram comparison is case sensitive or not and
 * whilespace is significant or not.
 */
bool is_permutation( const std::string & s1,
                     const std::string & s2 )
{
    if ( s1.length() != s2.length() )
        return false;

    std::unordered_map< char, int > hashmap;
    for ( const auto & c : s1 )
        ++hashmap[ c ];

    for ( const auto & c : s2 )
    {
        if ( hashmap.find( c ) != hashmap.end() )
        {
            return false;
        }
        else
        {
            --hashmap[ c ];
            if ( hashmap[ c ] < 0 )
                return false;
        }
    }

    return true;
}

bool is_permutation2( const std::string & s1,
                     const std::string & s2 )
{
    if ( s1.length() != s2.length() )
        return false;
    
    std::string s1_copy( s1 );
    std::string s2_copy( s2 );
    
    std::sort( s1_copy.begin(), s1_copy.end() );
    std::sort( s2_copy.begin(), s2_copy.end() );
    
    return s1_copy == s2_copy;
}

int main()
{
    std::string s1( "aab" );
    std::string s2( "abb" );

    std::cout << is_permutation( s1, s2 ) << std::endl;
    std::cout << is_permutation2( s1, s2 ) << std::endl;

    return 0;
}
