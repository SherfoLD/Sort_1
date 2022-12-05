//
//  List.h
//  Sort_1
//
//  Created by Dmitry Savelev on 06.11.2022.
//

#ifndef List_h
#define List_h

#include "Node.h"

class List{
private:
    Node* head;
    Node *sorted;
    int length;
    
    void insert(Node* insertedNode);

public:
    List();
    ~List();
    void push(int newValue);
    int pop();
    void print();
    void sort();
    void sortForQueue();
    bool isEmpty();
    int get(int index);
    void set(int index, int newValue);
};



#endif /* List_h */
