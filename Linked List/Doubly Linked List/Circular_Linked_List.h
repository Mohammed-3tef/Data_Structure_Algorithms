#ifndef LINKED_LIST_CIRCULAR_LINKED_LIST_H
#define LINKED_LIST_CIRCULAR_LINKED_LIST_H

#include <bits/stdc++.h>
#include "Doubly_Linked_List.h"
using namespace std;

template<typename T>
class CircularLinkedList : public DoublyLinkedList<T>{
public:
    CircularLinkedList() : DoublyLinkedList<T>() {}

    void insert(const T& data){
        auto* newNode = new doubleNode<T>(data);

        if (this->head == nullptr) {
            this->head = this->tail = newNode;
            newNode->next = newNode;
            newNode->prev = newNode;
        }
        else {
            newNode->prev = this->tail;
            newNode->next = this->head;
            this->head->prev = newNode;
            this->tail->next = newNode;
            this->tail = newNode;
        }

        this->size++;
    }

    void print() const {
        doubleNode<T> *current = this->head;

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
            if (current == this->head) break;
        }
        cout << endl;
    }
};

#endif //LINKED_LIST_CIRCULAR_LINKED_LIST_H