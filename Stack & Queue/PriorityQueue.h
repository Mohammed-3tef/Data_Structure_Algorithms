#ifndef STACK_QUEUE_PRIORITYQUEUE_H
#define STACK_QUEUE_PRIORITYQUEUE_H

#include <bits/stdc++.h>
using namespace std;

template<typename T>
class PriorityQueue {
private:
    struct Item{
        int priority;
        T data;
    };

    Item *arr;
    int arrSize;

    void insertionSort(Item *_arr, const int& _size){
        if (_size == 0) return;

        for (int i = 1; i < _size; ++i) {
            Item temp = _arr[i];
            int j = i - 1;
            while (j >= 0 && _arr[j].priority < temp.priority) {
                _arr[j + 1] = _arr[j];
                j--;
            }
            _arr[j + 1] = temp;
        }
    }

public:
    PriorityQueue(){
        this->arrSize = 0;
        this->arr = new Item[this->arrSize];
    }

    int size(){
        return this->arrSize;
    }

    bool empty() {
        return this->arrSize == 0;
    }

    void clear(){
        delete this->arr;
        this->arrSize = 0;
    }

    void enqueue(const T& _data, const int& _priority = 1){
        Item *newArr = new Item[this->arrSize +1];
        for (int i = 0; i < this->arrSize; ++i) {
            newArr[i] = this->arr[i];
        }
        newArr[this->arrSize].priority = _priority;
        newArr[this->arrSize].data = _data;

        insertionSort(newArr, this->arrSize +1);

        delete this->arr;
        this->arr = newArr;
        this->arrSize++;
    }

    void dequeue(){
        Item *newArr = new Item[this->arrSize -1];
        for (int i = 1; i < this->arrSize; ++i) {
            newArr[i-1] = this->arr[i];
        }

        delete this->arr;
        this->arr = newArr;
        this->arrSize--;
    }

    T top(){
        return this->arr[0].data;
    }

    void print(){
        for (int i = 0; i < this->arrSize; ++i) {
            cout << this->arr[i].data << " \n"[i == this->arrSize -1];
        }
    }
};


#endif //STACK_QUEUE_PRIORITYQUEUE_H
