#include <bits/stdc++.h>
#include "Doubly_Linked_List.h"
#include "Circular_Linked_List.h"
using namespace std;

int main() {
    auto *d1 = new DoublyLinkedList<int>();
    d1->insert(5);
    d1->insert(3);
    d1->insert(1);
    d1->insert(2);

    cout << "The First Doubly Linked List: ";
    d1->print();

    cout << "Number of Elements: " << d1->length() << endl;
    cout << "The First Element: " << d1->front() << endl;
    cout << "The Last Element: " << d1->back() << endl;

    if (d1->isEmpty()) cout << "The First Doubly Linked List is Empty..." << endl;
    else cout << "The First Doubly Linked List is NOT Empty..." << endl;

    cout << "The First Doubly Linked List after pop_back: ";
    d1->pop_back();
    d1->print();

    int index = 1;
    cout << "The Element at index " << index << " : " << d1->at(index) << endl;

    cout << "The First Doubly Linked List after deleted the element at index " << index << " : ";
    d1->erase(index);
    d1->print();

    if (d1->search(10)) cout << "The Element is Found..." << endl;
    else cout << "The Element is NOT Found..." << endl;

    cout << endl;

    cout << "The Second Doubly Linked List: ";
    auto* d2 = d1;
    d2->print();

    cout << endl;

    cout << "After cleared: " << endl;
    d1->clear();
    if (d1->isEmpty()) cout << "The First Doubly Linked List is Empty..." << endl;
    else cout << "The First Doubly Linked List is NOT Empty..." << endl;


    cout << endl << "-----------------------------------------" << endl << endl; // -- CIRCULAR LINKED LIST


    auto *c1 = new CircularLinkedList<int>();
    c1->insert(4);
    c1->insert(5);
    c1->insert(2);
    c1->insert(1);
    c1->insert(3);

    cout << "The First Circular Linked List: ";
    c1->print();

    cout << "Number of Elements: " << c1->length() << endl;
    cout << "The First Element: " << c1->front() << endl;
    cout << "The Last Element: " << c1->back() << endl;

    if (c1->isEmpty()) cout << "The First Circular Linked List is Empty..." << endl;
    else cout << "The First Circular Linked List is NOT Empty..." << endl;

    cout << "The First Circular Linked List after pop_back: ";
    c1->pop_back();
    c1->print();

    cout << "The Element at index " << index << " : " << c1->at(index) << endl;

    cout << "The First Circular Linked List after deleted the element at index " << index << " : ";
    c1->erase(index);
    c1->print();

    if (c1->search(10)) cout << "The Element is Found..." << endl;
    else cout << "The Element is NOT Found..." << endl;

    cout << endl;

    cout << "The Second Circular Linked List: ";
    auto* c2 = c1;
    c2->print();

    cout << endl;

    cout << "After cleared: " << endl;
    c1->clear();
    if (c1->isEmpty()) cout << "The First Circular Linked List is Empty..." << endl;
    else cout << "The First Circular Linked List is NOT Empty..." << endl;

    return 0;
}