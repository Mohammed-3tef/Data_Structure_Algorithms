#ifndef LINKED_LIST_UNORDERED_LINKED_LIST_H
#define LINKED_LIST_UNORDERED_LINKED_LIST_H

#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Node{
public:
    int data {};
    Node *next;

    Node(){
        this->next = nullptr;
    };

    explicit Node(const T& data){
        this->data = data;
        this->next = nullptr;
    };
};

template<typename T>
class unorderedLinkedList{
protected:
    Node<T> *head;
    int size;
public:
    unorderedLinkedList(){
        this->head = nullptr;
        this->size = 0;
    }

    ~unorderedLinkedList(){
        Node<T> *current;
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
        Node<T> *current = this->head;
        while (current->next != 0) {
            current = current->next;
        }
        return current->data;
    }

    bool search(const T& data){
        Node<T>* current = this->head;
        bool found = false;

        while (current != NULL && !found){
            if (current->data == data)
                found = true;
            else current = current->next;
        }

        return found;
    }

    virtual void insert(const T& data){
        auto *node = new Node<T>(data);

        if (this->head == nullptr) {
            this->head = node;
        }
        else {
            Node<T> *current = this->head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = node;
        }
        this->size++;
    }

    void pop_back(){
        if (this->head == nullptr) return;

        if (this->head->next == nullptr) {
            delete this->head;
            this->head = nullptr;
            this->size--;
            return;
        }

        Node<T> *tailCurrent = this->head;
        while (tailCurrent->next->next != nullptr) {
            tailCurrent = tailCurrent->next;
        }

        delete tailCurrent->next;
        tailCurrent->next = nullptr;
        this->size--;
    }

    void erase(const int& position){
        if (position < 0 || position >= this->size) return;

        if (position == 0) {
            Node<T> *temp = this->head;
            this->head = this->head->next;
            delete temp;
            this->size--;
            return;
        }

        Node<T> *tailCurrent = this->head;
        Node<T> *current = tailCurrent->next;
        for (int i = 0; i < position - 1; ++i) {
            tailCurrent = tailCurrent->next;
            current = current->next;
        }

        tailCurrent->next = current->next;
    }

    void clear(){
        Node<T> *current;
        while(this->head != NULL) {
            current = this->head;
            this->head = this->head->next;
            delete current;
        }
        this->size = 0;
    }

    void print() const {
        Node<T> *current = this->head;

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
        delete[] current;
    }

    T at(const int& position) const {
        Node<T> *current = this->head;
        for (int i = 0; i < position; ++i) {
            current = current->next;
        }

        return current->data;
    }

    void operator = (const unorderedLinkedList<T> *other){
        this->head = other->head, this->size = other->size;

        Node<T>* currentFirstList = this->head;
        Node<T>* currentSecondList = other->head;
        while (currentFirstList != nullptr && currentSecondList != nullptr) {
            currentFirstList = currentFirstList->next;
            currentSecondList = currentSecondList->next;
        }

        delete[] currentFirstList;
        delete[] currentSecondList;
    }
};

#endif //LINKED_LIST_UNORDERED_LINKED_LIST_H