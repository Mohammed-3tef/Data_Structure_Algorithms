#include <bits/stdc++.h>
using namespace std;

template<typename T>
void operator<<(ostream &out, vector<T> &arr) {
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

// -------------------------------- HEAP SORT
/*
--> Time Complexity:
    * Best Case: O(n log n).
    * Average Case: O(n log n).
    * Worst Case: O(n log n).
--> Space Complexity: O(1) for in-place sorting.
--> Adaptive: No.
--> Stable: No.
--> In-Place: Yes.
*/

// -------------------------------- FOR VECTORS

template<typename T>
void minHeapify(vector<T> &arr, const int& arrSize, const int& index){
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

template<typename T>
void buildMinHeap(vector<T> &arr, const int& n){
    for (int i = n/2 -1; i >= 0; i--) {
        minHeapify(arr, n, i);
    }
}

template<typename T>
void maxHeapify(vector<T> &arr, const int& arrSize, const int& index){
    int max = index;
    int left = (2 * index) + 1;
    int right = (2 * index) + 2;

    if (left < arrSize && arr[left] > arr[max]) max = left;
    if (right < arrSize && arr[right] > arr[max]) max = right;

    if (max != index){
        swap(arr[index], arr[max]);
        maxHeapify(arr, arrSize, max);
    }
}

template<typename T>
void buildMaxHeap(vector<T> &arr, const int& n){
    for (int i = n/2 -1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

template<typename T>
void heapSort(vector<T> &arr, const int& n, const string& orderBy = "asc"){
    if (orderBy == "desc"){
        buildMinHeap(arr, n);
        for (int i = n-1; i > 0; i--) {
            swap(arr[0], arr[i]);
            minHeapify(arr, i, 0);
        }
    } else {
        buildMaxHeap(arr, n);
        for (int i = n-1; i > 0; i--) {
            swap(arr[0], arr[i]);
            maxHeapify(arr, i, 0);
        }
    }
}

// -------------------------------- FOR ARRAYS

template<typename T>
void minHeapify(T arr[], const int& arrSize, const int& index){
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

template<typename T>
void buildMinHeap(T arr[], const int& n){
    for (int i = n/2 -1; i >= 0; i--) {
        minHeapify(arr, n, i);
    }
}

template<typename T>
void maxHeapify(T arr[], const int& arrSize, const int& index){
    int max = index;
    int left = (2 * index) + 1;
    int right = (2 * index) + 2;

    if (left < arrSize && arr[left] > arr[max]) max = left;
    if (right < arrSize && arr[right] > arr[max]) max = right;

    if (max != index){
        swap(arr[index], arr[max]);
        maxHeapify(arr, arrSize, max);
    }
}

template<typename T>
void buildMaxHeap(T arr[], const int& n){
    for (int i = n/2 -1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

template<typename T>
void heapSort(T arr[], const int& n, const string& orderBy = "asc"){
    if (orderBy == "desc"){
        buildMinHeap(arr, n);
        for (int i = n-1; i > 0; i--) {
            swap(arr[0], arr[i]);
            minHeapify(arr, i, 0);
        }
    } else {
        buildMaxHeap(arr, n);
        for (int i = n-1; i > 0; i--) {
            swap(arr[0], arr[i]);
            maxHeapify(arr, i, 0);
        }
    }
}

// -------------------------------- MAIN FUNCTION

int main() {
    vector<int> v = {3, 10, 2, 5, 8, 7, 9, 4, 1, 6};
    int vSize = int(v.size());
    int arr[] = {3, 10, 2, 5, 8, 7, 9, 4, 1, 6};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    heapSort(v, vSize);
    heapSort(arr, arrSize, "desc");

    cout << v;
    print(arr, arrSize);
    return 0;
}