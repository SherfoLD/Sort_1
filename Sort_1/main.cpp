#include <iostream>
#include <ctime>
#include "List.h"
#include "Node.h"
int main()
{
    List list;
    
    for (int i=0; i<10000; i++) {
        list.push(rand()%100);
    };
    
    list.print();
    list.sort();
    list.print();
}

