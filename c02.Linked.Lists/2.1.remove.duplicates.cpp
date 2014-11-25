#include <iostream>
#include <unordered_set>

struct Node {
    int val;
    Node * next;
    Node( int v ) : val( v ), next( nullptr ) {}
};

void remove_duplicates( Node * head )
{
    if ( ! head )
        return;

    Node * p = head;
    std::unordered_set< int > s;
    s.insert( p->val );
    while ( p->next )
    {
        if ( s.find( p->next->val ) == s.end() )
        {
            s.insert( p->next->val );
            p = p->next;
        }
        else
        {
            Node * tmp = p->next;
            p->next = p->next->next;
            delete tmp;
        }
    }
}

void remove_duplicates2( Node * head )
{
    if ( ! head )
        return;

    Node * p = head;
    while ( p )
    {
        int v = p->val;
        Node * p2 = p;
        while ( p2->next )
        {
            if ( p2->next->val != v )
            {
                p2 = p2->next;
            }
            else
            {
                Node * tmp = p2->next;
                p2->next = p2->next->next;
                delete tmp;
            }
        }
        p = p->next;
    }
}

void print_list( Node * p )
{
    while ( p )
    {
        std::cout << p->val << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

int main()
{
    {
    Node * p1 = new Node( 1 );
    Node * p2 = new Node( 1 );
    Node * p3 = new Node( 1 );
    Node * p4 = new Node( 2 );
    Node * p5 = new Node( 3 );
    Node * p6 = new Node( 3 );
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = p6;
    
    print_list( p1 );
    
    remove_duplicates( p1 );
    
    print_list( p1 );
    }

    {
    Node * p1 = new Node( 1 );
    Node * p2 = new Node( 1 );
    Node * p3 = new Node( 1 );
    Node * p4 = new Node( 2 );
    Node * p5 = new Node( 3 );
    Node * p6 = new Node( 3 );
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = p6;
    
    print_list( p1 );
    
    remove_duplicates2( p1 );
    
    print_list( p1 );
    }
    
    return 0;
}

