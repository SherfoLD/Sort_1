#include <iostream>
#include <chrono>
#include "List.h"
#include "Node.h"

int main()
{
    List list;
    
    for (int i=0; i<1000000; i++) {
        list.push(rand());
    };
    std::cout << "Original array:\n";
    //list.print();
    
    auto start = std::chrono::steady_clock::now();
    
    list.sort();
    
    auto end = std::chrono::steady_clock::now();
    
    std::cout << "Sorted array:\n";
    //list.print();
    
    std::cout<< "Elapsed time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() << " ms\n";
}

