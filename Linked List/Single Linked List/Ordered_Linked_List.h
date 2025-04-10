#ifndef LINKED_LIST_ORDERED_LINKED_LIST_H
#define LINKED_LIST_ORDERED_LINKED_LIST_H

#include <bits/stdc++.h>
#include "Unordered_Linked_List.h"
using namespace std;

template<typename T>
class OrderedLinkedList : public unorderedLinkedList<T>{
public:
    OrderedLinkedList() : unorderedLinkedList<T>(){}

    ~OrderedLinkedList() {
        Node<T> *current;
        while (this->head != NULL) {
            current = this->head;
            this->head = this->head->next;
            delete current;
        }
        this->size = 0;
    }

    void insert(const T& data){
        Node<T> *current, *trailCurrent;
        auto *newNode = new Node<T>(data);
        bool found;

        if (this->head == NULL) {
            this->head = newNode;
            this->size++;
        }
        else {
            current = this->head;
            found = false;

            while (current != NULL && !found) {
                if (current->data >= data)
                    found = true;
                else {
                    trailCurrent = current;
                    current = current->next;
                }
            }

            if (current == this->head){
                newNode->next = this->head;
                this->head = newNode;
                this->size++;
            }
            else {
                trailCurrent->next = newNode;
                newNode->next = current;
                this->size++;
            }
        }
    }
};

#endif //LINKED_LIST_ORDERED_LINKED_LIST_H
