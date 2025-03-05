#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <iostream>
using namespace std;

// Insertion Sort:
// --> Time Complexity:
//     - Best Case: O(n) --> When the array is already sorted.
//     - Average Case: O(n^2)
//     - Worst Case: O(n^2) --> When the array is sorted in reverse order.
// --> Space Complexity = O(1)

template<class T>
void insertionSort(vector<T>& arr) {
    int size = int(arr.size());
    for (int i = 1; i < size; ++i) {
        T temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

// Selection Sort:
// --> Time Complexity:
//     - Best Case: O(n^2) --> When the array is sorted in reverse order.
//     - Average Case: O(n^2)
//     - Worst Case: O(n^2) --> When the array is already sorted.
// --> Space Complexity = O(1)

template<class T>
void selectionSort(vector<T>& arr) {
    int size = int(arr.size());

    for (int i = 0; i < size -1; ++i) {
        int currentIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[currentIndex] > arr[j]) currentIndex = j;
        }
        swap(arr[i], arr[currentIndex]);
    }
}

// Bubble Sort:
// --> Time Complexity:
//     - Best Case: O(n) --> When the array is already sorted.
//     - Average Case: O(n^2)
//     - Worst Case: O(n^2) --> When the array is sorted in reverse order.
// --> Space Complexity = O(1)

template<class T>
void bubbleSort(vector<T>& arr) {
    int size = int(arr.size());

    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j+1]) swap(arr[j + 1], arr[j]);
        }
    }
}


// Shell Sort:
// --> Time Complexity:
//    - Best Case: O(n) --> When the array is already sorted.
//    - Average Case: O(n^1.5)
//    - Worst Case: O(n^2) --> When the array is sorted in reverse order.
// --> Space Complexity = O(n)

template<class T>
void shellSort(vector<T>& arr) {
    int size = arr.size();

    for (int gap = size /2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; ++i) {
            T temp = arr[i];
            int j = i;

            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

#endif //SORTING_ALGORITHMS_H