#ifndef STACK_QUEUE_QUEUE_H
#define STACK_QUEUE_QUEUE_H

#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Queue {
    T* arr;
    int size;
public:
    Queue(){
        this->size = 0;
        arr = new T(this->size);
    }

    virtual ~Queue() {
        delete[] this->arr;
    }

    void clear(){
        this->size = 0;
    }

    bool isEmpty(){
        return (this->size == 0);
    }

    T findMin() const {
        T min = this->arr[0];
        for (int i = 1; i < this->size; ++i) {
            if (min > this->arr[i]) min = this->arr[i];
        }
        return min;
    }

    T findMax() const {
        T max = this->arr[0];
        for (int i = 1; i < this->size; ++i) {
            if (max < this->arr[i]) max = this->arr[i];
        }
        return max;
    }

    T front() const {
        return this->arr[0];
    }

    T back() const {
        return this->arr[this->size - 1];
    }

    void enqueue(const T& data){
        T *newArr = new T(++this->size);
        for (int i = 0; i < this->size; ++i) {
            newArr[i] = this->arr[i];
        }
        newArr[this->size - 1] = data;
        delete[] this->arr;
        this->arr = newArr;
    }

    void dequeue(){
        T *newArr = new T(this->size - 1);
        for (int i = 1; i < this->size; ++i) {
            newArr[i-1] = this->arr[i];
        }
        delete[] this->arr;
        this->arr = newArr;
        this->size--;
    }

    void print(){
        for (int i = 0; i < this->size; ++i) {
            cout << this->arr[i] << " \n"[i == this->size - 1];
        }
    }
};


#endif //STACK_QUEUE_QUEUE_H
