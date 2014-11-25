#include <iostream>

struct Node {
    int val;
    Node * next;
    Node( int v ) : val( v ), next( nullptr ) {}
};

int kth_to_last( Node * head, int k )
{
   if ( ! head )
       return 0;
    
   int i = kth_to_last( head->next, k ) + 1;
   if ( i == k )
   {
       std::cout << head->val << std::endl;
   }
   return i;
}

Node * kth_to_last( Node * head, int k, int & i )
{
    if ( ! head )
        return nullptr;

    Node * p = kth_to_last( head->next, k, i );
    i = i + 1;
    if ( i == k )
        return head;

    return p;
}

Node * kth_to_last2( Node * head, int k )
{
    if ( k <= 0 )
        return nullptr;

    Node * p = head;
    Node * p2 = head;
    while ( k > 0 && p2 )
    {
        --k;
        p2 = p2->next;
    }
    if ( k > 0 )
        return nullptr;
    
    while ( p2 )
    {
        p2 = p2->next;
        p = p->next;
    }
    
    return p;
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

    kth_to_last( p1, 2 );

    int i = 0;
    Node * p = kth_to_last( p1, 2, i );
    std::cout << p->val << std::endl;

    Node * pp = kth_to_last2( p1, 4 );
    std::cout << pp->val << std::endl;
    
    return 0;
}
