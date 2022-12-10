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
    count = 0;
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

int List::get(int index){ //+1
    if (isEmpty()) //+2
        throw 0;
    if (index < 0 || index >= length) //+3
        throw 0;
     
    for (int i = 0; i < index; i++){ //+2
        push(pop()); //+3
        count += 5;
    }//+2
    int result = head -> getValue(); //+3
    
    for (int i = 0; i < length - index; i++){ //+2
        push(pop()); //+3
        count += 5;
    }//+2
    count += 13;
    return result; //+1
}

void List::set(int index, int newValue){ //+2
    if (isEmpty()) //+2
        throw 0;
    if (index < 0 || index >= length) //+3
        throw 0;
    
    for (int i = 0; i < index; i++){ //+2
        push(pop()); //+3
        count += 5;
    }//+2
    head -> setValue(newValue); //+3
    
    for (int i = 0; i < length - index; i++){ //+2
        push(pop()); //+3
        count +=5;
    }//+2
    count += 14;
}

void List::push(int newValue){ //+1
    Node* newNode = new Node(newValue); //+3
    if (isEmpty()) //+2
        head = newNode; //+1
    else {
        Node *currentNode = head; //+1
        while(currentNode -> getNext()) { //+2
            currentNode = currentNode -> getNext(); // +3
            count +=5;
        }
        currentNode -> setNext(newNode); // +3
    }
    length++; //+1
    count += 12;
}

int List::pop(){
    if (isEmpty()) //+2
        throw 0;
    
    Node* nextNode = head -> getNext(); //+3
    int headValue = head -> getValue(); //+3
    delete head; //+1
    
    head = nextNode; //+1
    length--; //+1
    
    count += 12;
    return headValue; //+1
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
    
    int j = 0; //+1
    
    for (int i = 1; i < length; i++){ //+2
        j = i; //+1

        int _j = get(j); int _j1 = get(j-1); //+7
        while (_j < _j1){ //+5
            int swap = _j; //+1
            set(j, _j1); //+3
            set(j-1, swap); //+4
            j = j - 1; //+2
            
            if (j == 0) //+1
                break;
            _j = get(j); _j1 = get(j-1); //+7
            count += 19;
        }

        count += 3;
    }//+2
    count += 3;
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
