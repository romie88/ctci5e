#include <string>
#include <iostream>

bool isSubstring( const std::string & s, const std::string & ss )
{
    return s.find( ss ) != std::string::npos;
}

bool isRotation( const std::string s1, const std::string & s2 )
{
    if ( s1.length() != s2.length() )
        return false;

    std::string s( s1 );
    s.append( s1 );

    return isSubstring( s, s2 );
}

int main()
{
    std::string s1 = "waterbottle";
    std::string s2 = "erbottlewat";

    std::cout << isRotation( s1, s2 ) << std::endl;

    return 0;
}
