#include <iostream>
#include <stack>

struct Node {
    char c;
    Node * next;
    Node( int cc ) : c( cc ), next( nullptr ) {}
};

//return a pointer before end
Node * find_last( Node * start, Node * end )
{
    if ( ! start )
        return nullptr;

    while ( start->next )
    {
        if ( start->next == end )
        {
            return start;
        }
        else
            start = start->next;
    }
    
    return ( ! end ) ? start : nullptr;
}

bool is_palindrome( Node * head )
{
    Node * p1 = head;
    Node * p2 = find_last( p1, nullptr );
    while ( p1 != p2 )
    {
        if ( p1->c != p2->c )
            return false;
        else
        {
            p1 = p1->next;
            p2 = find_last( p1, p2 );
            if ( ! p2 )
                break;
        }
    }
    return true;
}

bool is_palindrome2( Node * head )
{
    Node * slow = head;
    Node * fast = head;
    
    std::stack< char > s;
    while ( fast && fast->next )
    {
        s.push( slow->c );
        slow = slow->next;
        fast = fast->next->next;
    }
    
    //skip the middle node if there are odd number of nodes
    if ( fast )
    {
        slow = slow->next;
    }
    
    while ( slow )
    {
        if ( s.top() != slow->c )
            return false;

        slow = slow->next;
        s.pop();
    }

    return true;
}

void is_palindrome_recursive( Node * head, int length, bool & result, Node * & tail )
{
    if ( ! head || ! length )
    {
        result = true;
        tail = nullptr;
        return;
    }
    else if ( length == 1 )
    {
        result = true;
        tail = head->next;
        return;
    }
    else if ( length == 2 )
    {
        result = head->c == head->next->c;
        tail = head->next->next;
        return;
    }
    
    bool result2 = false;
    Node * tail2 = nullptr;
    is_palindrome_recursive( head->next, length - 2, result2, tail2 );
    if ( ! result2 )
    {
        result = false;
    }
    else
    {
        result = ( head->c == tail2->c );
    }
    tail = tail2->next;
}

bool is_palindrome3( Node * head )
{
    int length = 0;
    Node * p = head;
    while ( p )
    {
        ++length;
        p = p->next;
    }
    
    bool result = false;
    Node * tail = nullptr;
    is_palindrome_recursive( head, length, result, tail );
    return result;
}

int main()
{
    {
    Node * p1 = new Node( 'a' );
    Node * p2 = new Node( 'b' );
    Node * p3 = new Node( 'c' );
    Node * p4 = new Node( 'd' );
    Node * p5 = new Node( 'c' );
    Node * p6 = new Node( 'b' );
    Node * p7 = new Node( 'a' );
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = p6;
    p6->next = p7;
    
    std::cout << is_palindrome( p1 ) << std::endl;
    std::cout << is_palindrome2( p1 ) << std::endl;
    std::cout << is_palindrome3( p1 ) << std::endl;
    }

    {
    Node * p1 = new Node( 'a' );
    Node * p2 = new Node( 'b' );
    Node * p3 = new Node( 'c' );
    Node * p4 = new Node( 'c' );
    Node * p5 = new Node( 'b' );
    Node * p6 = new Node( 'a' );
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = p6;
    
    std::cout << is_palindrome( p1 ) << std::endl;
    std::cout << is_palindrome2( p1 ) << std::endl;
    std::cout << is_palindrome3( p1 ) << std::endl;
    }

    {
    Node * p1 = new Node( 'a' );
    Node * p2 = new Node( 'b' );
    Node * p3 = new Node( 'a' );
    p1->next = p2;
    p2->next = p3;
    
    std::cout << is_palindrome( p1 ) << std::endl;
    std::cout << is_palindrome2( p1 ) << std::endl;
    std::cout << is_palindrome3( p1 ) << std::endl;
    }
    
    {
    Node * p1 = new Node( 'a' );
    Node * p2 = new Node( 'a' );
    p1->next = p2;
    
    std::cout << is_palindrome( p1 ) << std::endl;
    std::cout << is_palindrome2( p1 ) << std::endl;
    std::cout << is_palindrome3( p1 ) << std::endl;
    }

    {
    Node * p1 = new Node( 'a' );
    
    std::cout << is_palindrome( p1 ) << std::endl;
    std::cout << is_palindrome2( p1 ) << std::endl;
    std::cout << is_palindrome3( p1 ) << std::endl;
    }
    
    {
    std::cout << is_palindrome( nullptr ) << std::endl;
    std::cout << is_palindrome2( nullptr ) << std::endl;
    std::cout << is_palindrome3( nullptr ) << std::endl;
    }
    return 0;
}
