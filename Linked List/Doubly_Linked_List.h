#ifndef LINKED_LIST_DOUBLY_LINKED_LIST_H
#define LINKED_LIST_DOUBLY_LINKED_LIST_H

#include <bits/stdc++.h>
#include "Unordered_Linked_List.h"
using namespace std;

template<typename T>
class doubleNode {
public:
    int data {};
    doubleNode *next;
    doubleNode *prev;

    doubleNode(){
        this->next = nullptr;
        this->prev = nullptr;
    };

    explicit doubleNode(const T& data){
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    };
};

template<typename T>
class DoublyLinkedList {
protected:
    doubleNode<T> *head, *tail;
    int size;
public:
    DoublyLinkedList(){
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
    }

    ~DoublyLinkedList(){
        doubleNode<T> *current;
        while(this->head != NULL) {
            current = this->head;
            this->head = this->head->next;
            delete current;
        }
        this->size = 0;
    }

    bool isEmpty(){
        return (this->size == 0);
    }

    int length(){
        return this->size;
    }

    T front() const {
        return this->head->data;
    }

    T back() const {
        return this->tail->data;
    }

    bool search(const T& data){
        doubleNode<T>* current = this->head;
        bool found = false;

        while (current != NULL && !found){
            if (current->data == data)
                found = true;
            else current = current->next;
        }

        return found;
    }

    virtual void insert(const T& data){
        auto *newNode = new doubleNode<T>(data);

        if (this->head == nullptr) {
            this->head = newNode;
            this->tail = newNode;
        }
        else {
            this->tail->next = newNode;
            newNode->prev = this->tail;
            this->tail = newNode;
        }
        this->size++;
    }

    void pop_back(){
        if (this->head == nullptr) return;

        if (this->head->next == nullptr) {
            delete this->head;
            this->head = nullptr;
            this->tail = nullptr;
            this->size--;
            return;
        }

        doubleNode<T> *tailCurrent = this->tail;
        this->tail = this->tail->prev;
        delete tailCurrent;
        this->tail->next = nullptr;
        this->size--;
    }

    void erase(const int& position){
        if (position < 0 || position >= this->size) return;

        if (position == 0) {
            doubleNode<T> *temp = this->head;
            this->head = this->head->next;
            this->head->prev = nullptr;
            delete temp;
            this->size--;
            return;
        }

        if (position == this->size - 1) {
            pop_back();
            return;
        }

        doubleNode<T> *current = this->head;
        for (int i = 0; i < position; ++i) {
            current = current->next;
        }

        current->prev->next = current->next;
        if (current->next != nullptr) {
            current->next->prev = current->prev;
        }
        delete current;
        this->size--;
    }

    void clear(){
        doubleNode<T> *current;
        while(this->head != NULL) {
            current = this->head;
            this->head = this->head->next;
            delete current;
        }
        this->head = this->tail = nullptr;
        this->size = 0;
    }

    virtual void print() const {
        doubleNode<T> *current = this->head;

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    T at(const int& position) const {
        doubleNode<T> *current = this->head;
        for (int i = 0; i < position; ++i) {
            current = current->next;
        }

        return current->data;
    }

    void operator = (const DoublyLinkedList<T> *other){
        this->head = other->head, this->size = other->size;

        doubleNode<T>* currentFirstList = this->head;
        doubleNode<T>* currentSecondList = other->head;
        while (currentFirstList != nullptr && currentSecondList != nullptr) {
            currentFirstList = currentFirstList->next;
            (currentFirstList->next)->prev = currentFirstList;

            currentSecondList = currentSecondList->next;
            (currentSecondList->next)->prev = currentSecondList;
        }

        delete[] currentFirstList;
        delete[] currentSecondList;
    }
};

#endif //LINKED_LIST_DOUBLY_LINKED_LIST_H