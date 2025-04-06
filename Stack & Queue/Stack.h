#ifndef STACK_QUEUE_STACK_H
#define STACK_QUEUE_STACK_H

#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Stack {
private:
    T* arr;
    int size;
public:
    Stack(){
        this->size = 0;
        this->arr = new T(this->size) ;
    };

    bool isEmpty (){
        return (this->size == 0) ;
    }

    void clear() {
        this->size = 0;
    }

    T top() const {
        return arr[size - 1];
    };

    void pop(){
        T* newArr = new T(this->size -1);
        for (int i = 0; i < this->size -1; ++i) {
            newArr[i] = this->arr[i];
        }

        delete[] this->arr;
        this->arr = newArr;
        this->size--;
    };

    void push(const T& element){
        T* newArr = new T(this->size + 1);
        for (int i = 0; i < this->size ; ++i) {
            newArr[i] = this->arr[i];
        }

        newArr[this->size] = element;
        delete[] this->arr;
        this->arr = newArr;
        this->size++;
    };

    void print(){
        for (int i = this->size -1; i >= 0; --i) {
            cout << this->arr[i] << " \n"[i == 0];
        }
    }
};


#endif //STACK_QUEUE_STACK_H
