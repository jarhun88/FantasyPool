#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <string>
using namespace std;


class List {
private:

int index = 0;

int length = 0;

    struct Node {
        string data;
        Node * next;
    };

public:

string owner;

Node * head;

Node * tail;

List(string name);

void insertFront(string newData);

void insertBack(string newData);

void removeAtIndex(int index);

void removeHead();
// prints all values in linked list starting from head
void print();

void changeData(string oldData, string newData);

void incIndex();

string getDataAtIndex();

int getIndex();

int getLength();

};

#endif 