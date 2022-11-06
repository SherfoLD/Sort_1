//
//  List.cpp
//  Sort_1
//
//  Created by Dmitry Savelev on 06.11.2022.
//

#include <iostream>
#include "List.h"
#include "Node.h"

List::List(){ // List* list = new List(); и можно убирать
    head = nullptr;
    sorted = nullptr;
}

List::~List(){
    while (head)
    {
        Node* nextNode = head -> getNext();
        delete head;
        head = nextNode;
    };
}

void List::push(int newValue){
    Node* newNode = new Node(newValue);
    newNode -> setNext(head);
    head = newNode;
}

int List::pop(){
    Node* nextNode = head -> getNext();
    int headValue = head -> getValue();
    delete head;
    head = nextNode;
    
    return headValue;
}

void List::print(){
    Node* currentNode = head;
    while (currentNode) {
        printf("%d ", currentNode -> getValue());
        currentNode = currentNode -> getNext();
    };
    printf("\n");
}

void List::sort()
{
    Node *current = head;
    while (current)
    {
        Node *next = current -> getNext();
        insert(current);
        current = next;
    }
    head = sorted;
}

void List::insert(Node *insertedNode)
{
    if (!sorted || insertedNode -> getValue() <= sorted -> getValue()) //переопределяем голову в sorted
    {
        insertedNode -> setNext(sorted);
        sorted = insertedNode;
        return;
    }
    
    Node *current = sorted;
    while (current -> getNext() &&
           current -> getNext() -> getValue() <  insertedNode -> getValue())
        current = current -> getNext();   //ищем куда положить
    
    insertedNode -> setNext(current ->getNext());
    current -> setNext(insertedNode);
}
