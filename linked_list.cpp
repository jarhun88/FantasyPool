#include "linked_list.h"
#include <iostream>
#include <cstdlib>

using namespace std;


/**
 * Linked List Constructor
 */

List::List(string name){
    head = NULL;
    tail = NULL;
    owner = name;
}

/**
 * Insert new Node at the front (head) of the linked list
 * previous head is now at second of the linked list
 */
void List::insertFront(string newData){
    Node * node = new Node;
    node->data = newData;
    node->next = head;
    head = node;
    if (node->next == NULL){
        tail = node;
    }
    length++;
}

void List::insertBack(string newData){
    Node * node = new Node;
    node->data = newData;
    if (tail != NULL){
        tail->next = node;
        tail = node;
    }
    else tail = node;
    length++;
}

void List::removeHead(){
    Node * temp = head;
    head = temp->next;
    temp->next = NULL;
    delete temp;
    length--;
}
// prints all values in linked list starting from head
void List::print(){
    Node * curr = head;
    while (curr != NULL){
        cout << curr->data << " " << endl;
        curr = curr->next;
    }
}

void List::changeData(string oldData, string newData){
    Node * curr = head;
    while (curr != NULL){
        if (curr->data == oldData){
            curr->data = newData;
            return;
        }
        curr = curr->next;
    }
    cout << oldData << " is not in your team!" << endl;
}

void List::removeAtIndex(int index) {
    Node * curr = head;
    Node * pre;
    for (int i = 0; i < index; i++){
        pre = curr;
        curr = curr->next;
    }
    pre->next = curr->next;
    if (tail == curr){
        tail = pre;
    }
    delete curr;
    curr->next = NULL;
    length--;
}

void List::incIndex() {
    index++;
}

string List::getDataAtIndex() {
    Node * curr = head;
    for (int i = 0; i < index; i++){
        curr = curr->next;
    }
    return curr->data;
}

int List::getIndex() {
    return index;
}

int List::getLength() {
    return length;
}