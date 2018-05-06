#include "linked_list.h"
#include <iostream>
#include <cstdlib>

using namespace std;

/**
 * Linked List Constructor
 */

List::List(string name){
    head = NULL;
    owner = name;
}

/**
 * Insert new Node at the front (head) of the linked list
 * previous head is now at second of the linked list
 */
void List::insert(Node*& head, string newData){
    Node * curr = new Node;
    curr->data = newData;
    curr->next = head;
    head = curr;
}

void List::remove(Node*& head){
    Node * temp = head;
    head = temp->next;
    temp->next = NULL;
    delete temp;
}
// prints all values in linked list starting from head
void List::print(Node* head){
    Node * curr = head;
    while (curr != NULL){
        cout << curr->data << " " << endl;
        curr = curr->next;
    }
}

void List::changeData(Node* head, string oldData, string newData){
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