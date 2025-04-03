#include <bits/stdc++.h>
using namespace std;

#ifndef LINKED_LIST_LINKED_LIST_H
#define LINKED_LIST_LINKED_LIST_H

template<typename T>
struct Node {
    T data;
    Node *next;

    explicit Node(T data) {
        this->data = data;
        this->next = nullptr;
    }

    void printNode(){
        cout << this->data << endl;
    }
};

template<typename T>
class LinkedList {
private:
    Node<T> *head;
    int size;
public:
    LinkedList() {
        this->head = nullptr;
        this->size = 0;
    }

    ~LinkedList() {
        Node<T> *temp;
        while(this->head != NULL) {
            temp = head;
            this->head = this->head->next;
            delete[] temp;
        }
        this->size = 0;
    }

    bool isEmpty() {
        return (this->size == 0);
    }

    int length() {
        return this->size;
    }

    Node<T>* front() const {
        return this->head;
    }

    Node<T>* back() const {
        Node<T>* current = this->head;
        while (current->next != NULL) {
            current = current->next;
        }
        return current;
    }

    void insert(const T& newData) {
        auto* newNode = new Node<T>(newData);

        if (this->head == NULL) this->head = newNode;
        else {
            Node<T>* current = this->head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }

        this->size++;
    }

    void deleteByValue(const T& deleteItem) {
        Node<T>* current = this->head;
        Node<T>* previous = this->head;

        if (current->data == deleteItem) {
            this->head = current->next;
        }

        else {
            while (current->data != deleteItem) {
                previous = current;
                current = current->next;
                if (current == NULL) return;
            }
            previous->next = current->next;
        }

        delete[] current;
        this->size--;
    }

    void deleteByIndex(const T& index) {
        Node<T>* current = this->head;
        Node<T>* previous = this->head;

        if (index == 0) {
            this->head = current->next;
            delete[] current;
            this->size--;
            return;
        }

        for (int i = 1; i < index; ++i) {
            previous = current;
            current = current->next;
        }
        previous->next = current->next;

        delete[] current;
        this->size--;
    }

    Node<T>* get(const int& index) {
        if (index < 0 || index >= this->size) return NULL;

        Node<T>* tempNode = this->head;
        for (int i = 1; i < index; ++i) {
            tempNode = tempNode->next;
        }

        return tempNode;
    }

    bool search(const T& searchItem) {
        bool found = false;
        Node<T> *current = this->head;

        while (current != NULL && !found){
            if (current->data >= searchItem) found = true;
            else current = current->link;
        }

        if (found) found = (current->info == searchItem);
        return found;
    }

    void print() {
        Node<T>* current = this->head;

        cout << "[";
        while (current != NULL) {
            if (current->next != nullptr) cout << current->data << ", ";
            else cout << current->data;
            current = current->next;
        }
        cout << "]";
        delete[] current;
    }
};

#endif //LINKED_LIST_LINKED_LIST_H
