#include <bits/stdc++.h>
#include "SortingAlgorithms.h"
using namespace std;

template<typename T>
void operator<<(ostream &out, vector<T> &arr) {
    for (auto i: arr) {
        cout << i << " ";
    }
    cout << endl;
}

template<typename T>
void operator<<(ostream &out, vector<vector<T>> &arr) {
    for (auto row: arr) {
        for (auto element: row) {
            cout << element << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    vector<int> arr = {3, 2, 5, 8, 15, 9, 4, 1};
//    insertionSort(arr);
//    bubbleSort(arr);
    selectionSort(arr);
    cout << arr;
}