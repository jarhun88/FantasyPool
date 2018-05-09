#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <string>
using namespace std;


class List {
private:

int index = 0;

    struct Node {
        string data;
        Node * next;
        int size = 0;
    };

public:

string owner;

Node * head;

List(string name);

void insert(string newData);

void removeHead();
// prints all values in linked list starting from head
void print();

void changeData(Node* head, string oldData, string newData);

void incIndex();

string getDataAtIndex();

int getSize();

};

#endif 