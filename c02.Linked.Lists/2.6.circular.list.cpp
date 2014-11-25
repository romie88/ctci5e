#include <iostream>

struct Node {
    int val;
    Node * next;
    Node( int v ) : val( v ), next( nullptr ) {}
};

Node * get_entrance_to_loop( Node * head )
{
    Node * slow = head;
    Node * fast = head;
    
    while ( fast )
    {
        slow = slow->next;
        fast = fast->next;
        if ( fast )
            fast = fast->next;
        
        if ( slow == fast )
            break;
    }

    if ( ! fast ) return nullptr;

    //slow and fast met
    slow = head;
    while ( slow != fast )
    {
        slow = slow->next;
        fast = fast->next;
    }
    
    return slow;
}

int main()
{
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

    Node * p = get_entrance_to_loop( p1 );
    if ( ! p )
        std::cout << "no loop found" << std::endl;
    }

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
    p6->next = p4;

    Node * p = get_entrance_to_loop( p1 );
    if ( ! p )
    {
        std::cout << "no loop found" << std::endl;
    }
    else
    {
        std::cout << p->val << " is the entrace node val" << std::endl;
    }
    }
    
    return 0;
}
