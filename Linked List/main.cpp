#include <bits/stdc++.h>
#include "Unordered_Linked_List.h"
#include "Ordered_Linked_List.h"
#include "Doubly_Linked_List.h"
#include "Circular_Linked_List.h"
using namespace std;

int main() {
//    auto *lt = new unorderedLinkedList<int>;
//    if (lt->isEmpty()) cout << "The First List is empty.." << endl;
//    else cout << "The First List is not empty.." << endl;
//
//    lt->insert(20);
//    lt->insert(10);
//
//    if (lt->isEmpty()) cout << "The First List is empty.." << endl;
//    else cout << "The First List is not empty.." << endl;
//
//    cout << lt->front() << endl;
//
//    lt->insert(5);
//    lt->insert(15);
//
//    cout << lt->back() << endl;
//
//    lt->print();
//
//    lt->pop_back();
//    lt->print();
//
//    cout << lt->at(2) << endl;
//
//    lt->erase(2);
//    lt->print();
//
//    if (lt->search(55)) cout << "Found" << endl;
//    else cout << "Not Found" << endl;
//
//    auto *lt2 = new unorderedLinkedList<int>;
//    lt2 = lt;
//    lt2->print();
//
//    cout << lt2->length() << endl;
//    lt2->clear();
//
//    if (lt2->isEmpty()) cout << "The second List is empty.." << endl;
//    else cout << "The second List is not empty.." << endl;
//
//    auto *lt3 = new OrderedLinkedList<int>();
//    lt3->insert(20);
//    lt3->insert(10);
//
//    if (lt3->isEmpty()) cout << "The Third List is empty.." << endl;
//    else cout << "The Third List is not empty.." << endl;
//
//    cout << lt3->front() << endl;
//
//    lt3->insert(5);
//    lt3->insert(15);
//
//    lt3->print();
//
//    auto *lt4 = new OrderedLinkedList<int>();
//    lt4 = lt3;
//    lt4->print();
//
    auto *d1 = new DoublyLinkedList<int>();
    d1->insert(5);
    d1->insert(3);
    d1->insert(1);
    d1->insert(2);
    d1->print();

    auto *d2 = new DoublyLinkedList<int>();
    d2 = d1;
    d2->print();

    auto *c1 = new CircularLinkedList<int>();
    c1->insert(5);
    c1->insert(4);
    c1->insert(3);
    c1->insert(2);
    c1->insert(1);

    c1->erase(2);
    c1->print();

    return 0;
}