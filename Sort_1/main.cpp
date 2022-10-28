#include <iostream>
#include <ctime>

struct Node
{
    int value;
    Node *next;
};

struct List
{
    Node *head;
    Node *sorted;

    void push(int val)
    {
        Node *startNode = new Node{val, NULL};
        startNode->next = head; //показать где голова
        head = startNode;
    }

    void print()
    {
        Node *node = head;
        while (node)
        {
            std::cout << node->value << " ";
            node = node->next;
        };
        std::cout << "/n";
    }

    void sort()
    {
        sorted = NULL;
        Node *current = head;
        while (current != NULL)
        {
            Node *next = current->next;
            insert(current);
            current = next;
        }
        head = sorted;
    }

    void insert(Node *nodeInsert)
    {
        if (sorted == NULL || nodeInsert->value <= sorted->value) //переопределяем голову в списке sorted
        {
            nodeInsert->next = sorted;
            sorted = nodeInsert;
        }
        else
        {
            Node *current = sorted;
            while (current->next != NULL && current->next->value < nodeInsert->value) //ищем куда положить в новом списке
            {
                current = current->next;
            }
            nodeInsert->next = current->next;
            current->next = nodeInsert;
        }
    }
};

int main()
{
    List list;

    list.head = NULL;
    
    for (int i = 0; i < 10; i++)
    {
        list.push(rand()%100);
    };
    
    unsigned long sortTimeStart =  clock();
    list.sort();
    unsigned long sortTimeEnd = clock();
    unsigned long sortTime = sortTimeEnd - sortTimeStart;
    
    printf("Sorting time: %lu ms\n", sortTime);
    list.print();
    
}
