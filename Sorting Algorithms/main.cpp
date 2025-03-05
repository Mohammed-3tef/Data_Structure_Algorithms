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

int main() {
    vector<int> arr = {3, 10, 2, 5, 8, 7, 9, 4, 1, 6};

//    insertionSort(arr);
//    bubbleSort(arr);
//    selectionSort(arr);
//    shellSort(arr);

    cout << arr;
}