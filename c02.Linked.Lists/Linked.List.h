#ifndef CITI5E_LINKED_LIST_H
#define CITI5E_LINKED_LIST_H

namespace ctci5e {

class LinkedList {
public:
    struct Node {
        int val;
        Node * next;
        Node( int v ) : val( v ), next( nullptr ) {}
    };
    
    LinkedList() : head( nullptr ) {}
    
    void appendNode( int v ) {
        
        Node * n = new Node( v );

        if ( ! head )
        {
            head = n;
            return;
        }
        
        Node * p = head;
        while ( p->next )
        {
            p = p->next;
        }
        p->next = new Node( v );
    }
    
    void deleteNode( int v ) {
        
        if ( ! head )
            return;

        if ( head->val == v )
        {
            Node * tmp = head;
            head = head->next;
            delete tmp;
            return;
        }

        Node * p = head;
        while ( p->next )
        {
            if ( p->next->val == v )
            {
                Node * tmp = p->next;
                p->next = p->next->next;
                delete tmp;
                break;
            }
        }
    }

    Node * getHead() { return head; }
    
    Node * head;
};

}//citi5e

#endif//CITI5E_LINKED_LIST_H
