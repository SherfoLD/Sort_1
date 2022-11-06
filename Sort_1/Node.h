//
//  Node.h
//  Sort_1
//
//  Created by Dmitry Savelev on 06.11.2022.
//

#ifndef Node_h
#define Node_h

struct Node{
private:
    int value;
    Node* next;

public:
    Node(int newValue);
    Node* getNext();
    void setNext(Node* nextNode);
    int getValue();
    void setValue(int newValue);
};

#endif /* Node_h */
