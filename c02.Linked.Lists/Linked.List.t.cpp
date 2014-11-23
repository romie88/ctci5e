#include "Linked.List.h"
#include <iostream>

using namespace ctci5e;

int main()
{
    LinkedList list;
    list.appendNode( 10 );
    std::cout << list.getHead()->val << std::endl;
    list.appendNode( 5 );
    std::cout << list.getHead()->next->val << std::endl;
    list.deleteNode( 10 );
    std::cout << list.getHead()->val << std::endl;

    return 0;
}
