#include <bits/stdc++.h>
#include "Ordered_Linked_List.h"
#include "Unordered_Linked_List.h"
using namespace std;

int main() {
    auto *lt = new unorderedLinkedList<int>;

    lt->insert(20);
    lt->insert(10);

    if (lt->isEmpty()) cout << "The First Unordered Linked List is empty.." << endl;
    else cout << "The First Unordered Linked List is NOT empty.." << endl;

    lt->insert(5);
    lt->insert(15);

    cout << "The First Unordered Linked List: ";
    lt->print();

    cout << "The First Element: " << lt->front() << endl;
    cout << "The Last Element: " << lt->back() << endl;
    cout << "Number of Element: " << lt->length() << endl;

    cout << "The First Unordered Linked List after pop_back: ";
    lt->pop_back();
    lt->print();

    int index = 1;
    cout << "The Element at index " << index << " : " << lt->at(index) << endl;
    cout << "The First Unordered Linked List after delete the element at index " << index << " : ";
    lt->erase(index);
    lt->print();

    if (lt->search(55)) cout << "Found" << endl;
    else cout << "Not Found" << endl;

    cout << endl;

    cout << "The Second Unordered Linked List: ";
    auto *lt2 = lt;
    lt2->print();

    cout << "After clearing: " << endl;
    lt2->clear();

    if (lt2->isEmpty()) cout << "The second Unordered Linked List is empty.." << endl;
    else cout << "The second Unordered Linked List is not empty.." << endl;

    cout << endl << "---------------------------------------------" << endl << endl;

    auto *lt3 = new OrderedLinkedList<int>();
    lt3->insert(20);
    lt3->insert(10);

    if (lt3->isEmpty()) cout << "The First Ordered Linked List is empty.." << endl;
    else cout << "The Third Ordered Linked List is not empty.." << endl;

    lt3->insert(5);
    lt3->insert(15);

    cout << "The First Ordered Linked List: ";
    lt3->print();

    cout << "The First Element: " << lt3->front() << endl;
    cout << "The Last Element: " << lt3->back() << endl;
    cout << "Number of Element: " << lt3->length() << endl;

    cout << "The First Ordered Linked List after pop_back: ";
    lt3->pop_back();
    lt3->print();

    cout << "The Element at index " << index << " : " << lt3->at(index) << endl;
    cout << "The First Ordered Linked List after delete the element at index " << index << " : ";
    lt3->erase(index);
    lt3->print();

    if (lt3->search(5)) cout << "Found" << endl;
    else cout << "Not Found" << endl;

    cout << endl;

    cout << "The Second Ordered Linked List: ";
    auto *lt4 = lt3;
    lt4->print();

    cout << "After clearing: " << endl;
    lt4->clear();

    if (lt4->isEmpty()) cout << "The second Unordered Linked List is empty.." << endl;
    else cout << "The second Unordered Linked List is not empty.." << endl;

    return 0;
}