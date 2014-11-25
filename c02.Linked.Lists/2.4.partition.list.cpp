#include <iostream>

struct Node {
    int val;
    Node * next;
    Node( int v ) : val( v ), next( nullptr ) {}
};

void print_list( Node * p )
{
    while ( p )
    {
        std::cout << p->val << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

Node * partition_list( Node * head, int x )
{
    Node * p = head;
    Node * new_head1 = nullptr;
    Node * new_head2 = nullptr;
    Node * p1 = nullptr;
    Node * p2 = nullptr;
    while ( p )
    {
        Node * next = p->next;
        p->next = nullptr;//isolate the current node from the source linked list

        if ( head->val < x )
        {
            if ( ! new_head1 )
            {
                new_head1 = p;
                p1 = p;
            }
            else
            {
                p1->next = p;
                p1 = p1->next;
            }
        }
        else
        {
            if ( ! new_head2 )
            {
                new_head2 = p;
                p2        = p;
            }
            else
            {
                p2->next = p;
                p2 = p2->next;
            }
        }

        p = next;
    }
    
    if ( ! new_head1 )
        return new_head2;

    p1->next = new_head2;
    return new_head1;
}

Node * partition_list2( Node * head, int x )
{
    Node * p = head;
    Node * p1 = nullptr;
    Node * p2 = nullptr;

    //this version insert in front of headers
    while ( p )
    {
        Node * next = p->next;
        p->next = nullptr;//isolate the current 
        
        if ( p->val < x )
        {
            //insert node in front
            p->next = p1;
            p1 = p;
        }
        else
        {
            //insert node in front
            p->next = p2;
            p2 = p;
        }
        
        p = next;
    }

    if ( ! p1 )
        return p2;

    Node * p3 = p1;
    while ( p3->next )
        p3 = p3->next;

    p3->next = p2;

    return p1;
}

int main()
{
    {
    Node * p1 = new Node( 6 );
    Node * p2 = new Node( 5 );
    Node * p3 = new Node( 4 );
    Node * p4 = new Node( 3 );
    Node * p5 = new Node( 2 );
    Node * p6 = new Node( 1 );
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = p6;
    
    print_list( p1 );

    Node * p = partition_list( p1, 0 );

    print_list( p );

    p = partition_list( p, 10 );

    print_list( p );

    p = partition_list( p, 2 );

    print_list( p );
    }
    
    {
    Node * p1 = new Node( 6 );
    Node * p2 = new Node( 5 );
    Node * p3 = new Node( 4 );
    Node * p4 = new Node( 3 );
    Node * p5 = new Node( 2 );
    Node * p6 = new Node( 1 );
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = p6;
    
    print_list( p1 );

    Node * p = partition_list2( p1, 0 );

    print_list( p );

    p = partition_list2( p, 10 );

    print_list( p );

    p = partition_list2( p, 2 );

    print_list( p );
    }

    return 0;
}
