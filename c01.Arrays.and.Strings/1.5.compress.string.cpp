#include <string>
#include <iostream>

using sz = std::string::size_type;

std::string compress( const std::string & s )
{
    std::string s2;
    for ( sz i = 0; i < s.length(); )
    {
        s2.append( 1, s[ i ] );
        sz j = i + 1;
        while ( j < s.length() && s[ i ] == s[ j ] )
            ++j;
        sz n = j - i;

        sz k = 1;
        sz n2 = n;
        while ( n2 )
        {
            k *= 10;
            n2 /= 10;
        }
        k /= 10;
        while ( k )
        {
            s2.append( 1, n / k + '0' );
            n %= k;
            k /= 10;
        }
        
        i = j;
    }
    
    if ( s2.length() >= s.length() )
        return s;
    else
        return s2;
}

//find out how many digits the input n has
//assume n >= 1
sz num_digits( sz n )
{
    sz k = 0;
    while ( n )
    {
        ++k;
        n /= 10;
    }
    return k;
}

//count the length of the compressed string
sz count_length( const std::string & s )
{
    if ( s.length() == 0 )
        return 0;
    
    sz len = 0;
    char last = s[ 0 ];
    sz count = 1;
    for ( sz i = 1; i < s.length(); ++i )
    {
        if ( s[ i ] == last )
        {
            ++count;
        }
        else
        {
            len += ( 1 + num_digits( count ) );
            last = s[ i ];
            count = 1;
        }
    }
    //dont forget to process the last repeated charaters!!!
    len += ( 1 + num_digits( count ) );
    
    return len;
}

void append_count( std::string & s, const sz count )
{
    sz count_copy = count;
    sz p = 1;
    while ( count_copy )
    {
        p *= 10;
        count_copy /= 10;
    }
    p /= 10;
    //for example, count_copy is 123, p = 100
    count_copy = count;
    while ( count_copy )
    {
        s.append( 1, count_copy / p + '0' );
        count_copy %= p;
        p /= 10;
    }
}

//return the compressed string
std::string compress2( const std::string & s )
{
    if ( count_length( s ) >= s.length() )
        return s;

    std::string s2;
    char last = s[ 0 ];
    sz count = 1;
    for ( sz i = 1; i < s.length(); ++i )
    {
        if ( s[ i ] == last )
        {
            ++count;
        }
        else
        {
            s2.append( 1, last );
            //append the count to s2
            append_count( s2, count );

            last = s[ i ];
            count = 1;
        }
    }
    s2.append( 1, last );
    append_count( s2, count );

    return s2;
}

int main()
{
    std::string s( "aabcccccaaa" );
    std::string s2 = compress( s );
    std::string s3 = compress2( s );

    std::cout << s2 << std::endl;
    std::cout << s3 << std::endl;

    return 0;
}
