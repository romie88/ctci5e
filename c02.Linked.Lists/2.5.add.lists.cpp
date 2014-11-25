#include <iostream>

struct Node {
    int val;
    Node * next;
    Node( int v ) : val( v ), next( nullptr ) {}
};

Node * add_lists( Node * p1, Node * p2 )
{
    Node * head = nullptr;
    Node * p = nullptr;
    int carry = 0;
    while ( p1 || p2 )
    {
        int sum = p1 ? p1->val : 0;
        sum += p2 ? p2->val : 0;
        sum += carry;

        Node * tmp = new Node( sum % 10 );
        if ( ! head )
        {
            head = tmp;
            p = tmp;
        }
        else
        {
            p->next = tmp;
            p = p->next;
        }
        carry = sum / 10;

        p1 = p1 ? p1->next : nullptr;
        p2 = p2 ? p2->next : nullptr;
    }
    if ( carry )
    {
        Node * tmp = new Node( carry );
        p->next = tmp;
    }

    return head;
}

Node * reverse_list( Node * head )
{
    Node * p = nullptr;
    while ( head )
    {
        Node * next = head->next;
        head->next = p;
        p = head;
        
        head = next;
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
    Node * p1 = new Node( 7 );
    Node * p2 = new Node( 1 );
    Node * p3 = new Node( 6 );
    p1->next = p2;
    p2->next = p3;

    Node * p4 = new Node( 5 );
    Node * p5 = new Node( 9 );
    Node * p6 = new Node( 2 );
    p4->next = p5;
    p5->next = p6;

    Node * result = add_lists( p1, p4 );
    print_list( result );
    
    p1 = reverse_list( p1 );
    p4 = reverse_list( p4 );
    result = add_lists( p1, p4 );
    result = reverse_list( result );
    print_list( result );
    
    return 0;
}
