#include <iostream>

struct Node {
    int val;
    Node * next;
    Node( int v ) : val( v ), next( nullptr ) {}
};

void split_into_two( Node * head, Node * & p1, Node * & p2 )
{
    Node * prev_slow = nullptr;
    Node * slow = head;
    Node * fast = head;

    while ( fast )
    {
        prev_slow = slow;
        slow = slow->next;
        fast = fast->next;
        if ( fast )
            fast = fast->next;
    }
    
    if ( prev_slow )
    {
        p1 = head;
        p2 = slow;
        prev_slow->next = nullptr;
    }
    else
    {
        p1 = head;
        p2 = nullptr;
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

Node * interweave( Node * n1, Node * n2 )
{
    if ( ! n1 )
        return n2;
    
    Node * prev_n1 = nullptr;
    Node * prev_n2 = nullptr;

    Node * head = n1;
    
    while ( n1 && n2 )
    {
        prev_n1 = n1;
        prev_n2 = n2;
        
        Node * tmp1 = n1->next;
        Node * tmp2 = n2->next;
        
        n1->next = n2;
        n2->next = tmp1;
        
        n1 = tmp1;
        n2 = tmp2;
    }
    
    if ( n2 )
    {
        prev_n2->next = n2;
    }
    
    return head;
}

int main()
{
    Node * p1 = new Node( 1 );
    Node * p3 = new Node( 3 );
    Node * p5 = new Node( 5 );
    Node * p7 = new Node( 7 );
    Node * p2 = new Node( 2 );
    Node * p4 = new Node( 4 );
    Node * p6 = new Node( 6 );
    Node * p8 = new Node( 8 );

    p1->next = p3;
    p3->next = p5;
    p5->next = p7;
    
    p7->next = p2;

    p2->next = p4;
    p4->next = p6;
    p6->next = p8;
    
    print_list( p1 );

    Node * n1 = nullptr;
    Node * n2 = nullptr;
    
    split_into_two( p1, n1, n2 );

    print_list( n1 );
    print_list( n2 );

    Node * p = interweave( p1, p2 );
    print_list( p );

    return 0;
}
