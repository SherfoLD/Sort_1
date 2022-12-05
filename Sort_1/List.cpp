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
    length = 0;
}

List::~List(){
    while (head)
    {
        Node* nextNode = head -> getNext();
        delete head;
        head = nextNode;
    };
}

bool List::isEmpty(){
    return head == nullptr;
}

int List::get(int index){
    if (isEmpty())
        throw 0;
    if (index < 0 || index >= length)
        throw 0;
    
    Node *currentNode = head;
    for (int i = 0; i < index; i++){
        currentNode = currentNode -> getNext();
    }
    int result = currentNode -> getValue();
    
    return result;
}

void List::set(int index, int newValue){
    if (isEmpty())
        throw 0;
    if (index < 0 || index >= length)
        throw 0;
    
    Node *currentNode = head;
    for (int i=0; i < index; i++){
        currentNode = currentNode -> getNext();
    }
    currentNode -> setValue(newValue);
}

void List::push(int newValue){
    Node* newNode = new Node(newValue);
    newNode -> setNext(head);
    head = newNode;
    
    length++;
}

int List::pop(){
    if (isEmpty())
        throw 0;
    
    Node* nextNode = head -> getNext();
    int headValue = head -> getValue();
    delete nextNode;
    
    head = nextNode;
    length--;
    
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

void List::sort(){
    int j = 0;
    
    for (int i = 1; i < length; i++){
        j = i;
        
        while (get(j) < get(j-1)){
            //std::cout << "j: " << j << " get j: " << get(j) << " get j-1: " << get(j-1) << "\n";
            int swap = get(j);
            set(j, get(j-1));
            set(j-1, swap);
            j = j - 1;
            if (j == 0 )
                break;
        }
    }
}

void List::sortForQueue()
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
