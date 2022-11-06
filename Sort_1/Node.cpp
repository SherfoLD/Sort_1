//
//  Node.cpp
//  Sort_1
//
//  Created by Dmitry Savelev on 06.11.2022.
//

#include <iostream>
#include "Node.h"

Node::Node(int newValue){
    value = newValue;
    next = nullptr;
}

Node* Node::getNext() {
    return next;
}

void Node::setNext(Node* nextNode) {
    next = nextNode;
}

int Node::getValue() {
    return value;
}

void Node::setValue(int newValue) {
    value = newValue;
}
