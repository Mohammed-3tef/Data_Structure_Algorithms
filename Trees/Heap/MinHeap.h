#ifndef HEAP_MINHEAP_H
#define HEAP_MINHEAP_H

#include <bits/stdc++.h>
using namespace std;

template<typename T>
class MinHeap {
private:
    T *_arr;
    int _size;

    void minHeapify(T *arr, const int& arrSize, const int& index){
        int min = index;
        int left = (2 * index) + 1;
        int right = (2 * index) + 2;

        if (left < arrSize && arr[left] < arr[min]) min = left;
        if (right < arrSize && arr[right] < arr[min]) min = right;

        if (min != index){
            swap(arr[index], arr[min]);
            minHeapify(arr, arrSize, min);
        }
    }

    void buildMinHeap(T *arr, const int& n){
        for (int i = n/2 -1; i >= 0; i--) {
            minHeapify(arr, n, i);
        }
    }

    int parentIndex(const int& index){
        return (index - 1) / 2;
    }

public:
    MinHeap(){
        this->_size = 0;
        this->_arr = new T[this->_size];
    }

    ~MinHeap(){
        this->_size = 0;
        delete[] this->_arr;
    }

    void clear(){
        this->_size = 0;
        delete[] this->_arr;
    }

    bool empty(){
        return this->_size == 0;
    }

    int leftChild(const int& index){
        const int childIndex = (index * 2) + 1;
        return this->_arr[childIndex];
    }

    int rightChild(const int& index){
        const int childIndex = (index * 2) + 2;
        return this->_arr[childIndex];
    }

    int parent(const int& index){
        const int parentIndex = (index - 1) / 2;
        return this->_arr[parentIndex];
    }

    int size(){
        return this->_size;
    }

    void push(const T& element){
        T *new_Arr = new T[this->_size + 1];
        for (int i = 0; i < this->_size; ++i) {
            new_Arr[i] = this->_arr[i];
        }
        new_Arr[this->_size++] = element;
        delete[] this->_arr;
        this->_arr = new_Arr;

        buildMinHeap(this->_arr, this->_size);
    }

    T min(){
        return this->_arr[0];
    }

    T extractMinimum(){
        T *new_Arr = new T[this->_size - 1];
        for (int i = 1; i < this->_size; ++i) {
            new_Arr[i - 1] = this->_arr[i];
        }
        T minimum = this->_arr[0];
        delete[] this->_arr;
        this->_arr = new_Arr;
        this->_size--;

        buildMinHeap(this->_arr, this->_size);
        return minimum;
    }

    void decreaseKey(int index, const T& value){
        if (value > this->_arr[index]) return;

        this->_arr[index] = value;
        while (index > 0 && this->_arr[parentIndex(index)] > this->_arr[index]) {
            swap(this->_arr[index], this->_arr[parentIndex(index)]);
            index = parentIndex(index);
        }
    }

    void sort(){
        buildMinHeap(this->_arr, this->_size);
        for (int i = this->_size - 1; i > 0; i--) {
            swap(this->_arr[0], this->_arr[i]);
            minHeapify(this->_arr, i, 0);
        }
    }

    void print(){
        for (int i = 0; i < this->_size; ++i) {
            cout << _arr[i] << " \n"[i == this->_size -1];
        }
    }
};


#endif //HEAP_MINHEAP_H
