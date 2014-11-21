#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

/**
 * First you should ask the interviewer if the string is an ASCII
 * string or a Unicode string.
 *
 * Assume taht the character set is ASCII.
 *
 * One simple optimization is to return false if the length of the
 * string is greater than the number of unique characters in the
 * alphabet.
 *
 * If the string only uses the lower case letters a through z,
 * we can use an int 32 bits as the flag vector.
 *
 * These implementations are O(n) time complexity and O(1) space
 * complexity.
 */
bool has_all_unique_chars( const std::string & s )
{
    if ( s.length() > 256 )
        return false;
    
    std::vector< bool > flag( 256, false );
    for ( const auto & c : s )
        if ( ! flag[ c ] )
            flag[ c ] = true;
        else
            return false;

    return true;
}

bool has_all_unique_chars_a_z( const std::string & s )
{
    if ( s.length() > 26 )
        return false;

    unsigned flag = 0;
    for ( const auto & c : s )
    {
        int val = c - 'a';
        if ( ( flag & ( 1 << val ) ) > 0 )
            return false;

        flag |= ( 1 << val );
    }

    return true;
}

/**
 * If no extra space is allowed, i.e., O(1) space complexity is a must.
 *
 * 1. Compare every character of the string to every other character
 *    of the string. O(n^2) time and O(1) space.
 *
 * 2. We can sort the string (or a copy of it) in O(nlog(n)) time and
 *    then linearly check the string for neighboring characters that
 *    are identical. However if a copy is required then O(n) space. 
 */
bool has_all_unique_chars_compare_pairwise( const std::string & s )
{
    using sz = std::string::size_type;
    for ( sz i = 0; i < s.length() - 1; ++i )
    {
        for ( sz j = i + 1; j < s.length(); ++j )
        {
            if ( s[ j ] == s[ i ] )
                return false;
        }
    }
    return true;
}

bool has_all_unique_chars_sort( const std::string & s )
{
    std::string s_copy( s );
    std::sort( s_copy.begin(), s_copy.end() );

    using sz = std::string::size_type;
    for ( sz i = 0; i < s.length() - 1; ++i )
    {
        if ( s[ i ] == s[ i + 1 ] )
            return false;
    }
    return true;
}

int main()
{
    std::string s1( "aabc" );
    std::cout << has_all_unique_chars( s1 ) << std::endl;
    std::cout << has_all_unique_chars_a_z( s1 ) << std::endl;
    std::cout << has_all_unique_chars_compare_pairwise( s1 ) << std::endl;
    std::cout << has_all_unique_chars_sort( s1 ) << std::endl;
    
    std::string s2( "abc" );
    std::cout << has_all_unique_chars( s2 ) << std::endl;
    std::cout << has_all_unique_chars_a_z( s2 ) << std::endl;
    std::cout << has_all_unique_chars_compare_pairwise( s2 ) << std::endl;
    std::cout << has_all_unique_chars_sort( s2 ) << std::endl;

    return 0;
}
