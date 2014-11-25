#include <iostream>

struct Node {
    int val;
    Node * next;
    Node( int v ) : val( v ), next( nullptr ) {}
};

bool delete_from_mid( Node * p )
{
    //if p is the last node of the list
    //the following wont work
    if ( ! p || ! p->next )
        return false;
    
    Node * tmp = p->next;
    p->val = p->next->val;
    p->next = p->next->next;
    delete tmp;
    
    return true;
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
    Node * p1 = new Node( 1 );
    Node * p2 = new Node( 2 );
    Node * p3 = new Node( 3 );
    Node * p4 = new Node( 4 );
    Node * p5 = new Node( 5 );
    Node * p6 = new Node( 6 );
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = p6;
    
    print_list( p1 );
    
    delete_from_mid( p3 );

    print_list( p1 );

    return 0;
}
