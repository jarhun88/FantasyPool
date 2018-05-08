#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <string>
using namespace std;


class List {
private:

    struct Node {
        string data;
        Node * next;
        int size;
    };

public:

string owner;

Node * head;

List(string name);

void insert(Node*& head, string newData);

void remove(Node*& head);
// prints all values in linked list starting from head
void print(Node* head);

void changeData(Node* head, string oldData, string newData);

void incrementNodeSize(Node* head);

};

#endif 