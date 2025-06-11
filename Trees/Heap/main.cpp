#include <bits/stdc++.h>
#include "MaxHeap.h"
#include "MinHeap.h"
using namespace std;

int main() {
    auto heap1 = new MaxHeap<int>();
    heap1->push(5);
    heap1->push(4);
    heap1->push(6);
    heap1->push(2);
    heap1->push(9);
    heap1->push(0);

    cout << "The Max Heap: ";
    heap1->print();

    cout << "Before deleting the root, the root = " << heap1->extractMaximum() << endl;
    cout << "The Max Heap's size = " << heap1->size() << endl;
    cout << "After deleting the root, the root = " << heap1->max() << endl;

    int index = 2;
    heap1->increaseKey(index, 10);

    cout << "After increasing the key at index " << index << " to 10" << endl;
    cout << "The Max Heap: ";
    heap1->print();


    heap1->sort();
    cout << "The Max Heap after sorting: ";
    heap1->print();

    heap1->clear();
    if (heap1->empty()) cout << "The Max Heap is empty now." << endl;
    else cout << "The Max Heap is not empty." << endl;

    cout << endl; // ---------------------------------------- MIN HEAP

    auto heap2 = new MinHeap<int>();
    heap2->push(5);
    heap2->push(4);
    heap2->push(6);
    heap2->push(2);
    heap2->push(9);
    heap2->push(0);

    cout << "The Min Heap: ";
    heap2->print();

    cout << "Before deleting the root, the root = " << heap2->extractMinimum() << endl;
    cout << "The Min Heap's size = " << heap2->size() << endl;
    cout << "After deleting the root, the root = " << heap2->min() << endl;

    index = 2;
    heap2->decreaseKey(index, 1);
    cout << "After decreasing the key at index " << index << " to 1" << endl;
    cout << "The Min Heap: ";
    heap2->print();

    heap2->sort();
    cout << "The Min Heap after sorting: ";
    heap2->print();

    heap2->clear();
    if (heap2->empty()) cout << "The Min Heap is empty now." << endl;
    else cout << "The Min Heap is not empty." << endl;

    return 0;
}