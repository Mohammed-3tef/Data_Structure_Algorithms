#include <bits/stdc++.h>
using namespace std;

template<typename T>
void operator<<(ostream &out, vector<T>& arr) {
    for (auto i: arr) {
        cout << i << " ";
    }
    cout << endl;
}

template<typename T>
void print(T arr[], const int& size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// -------------------------------- BUBBLE SORT
/*
--> Time Complexity:
    - Best Case: O(n)
    - Average Case: O(n^2)
    - Worst Case: O(n^2)
--> Space Complexity = O(1)
*/

template<typename T>
void bubbleSort(vector<T>& arr, const int& size) {
    if (size == 0) return;

    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j+1]) swap(arr[j + 1], arr[j]);
        }
    }
}

template<typename T>
void bubbleSort(T arr[], const int& size) {
    if (size == 0) return;

    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j+1]) swap(arr[j + 1], arr[j]);
        }
    }
}

// -------------------------------- MAIN FUNCTION

int main() {
    vector<int> v = {3, 10, 2, 5, 8, 7, 9, 4, 1, 6};
    int vSize = int(v.size());
    int arr[] = {3, 10, 2, 5, 8, 7, 9, 4, 1, 6};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(v, vSize);
    bubbleSort(arr, arrSize);

    cout << v;
    print(arr, arrSize);
}