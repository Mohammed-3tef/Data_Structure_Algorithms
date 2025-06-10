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

// -------------------------------- COUNT SORT
/*
Where n is the number of elements in the input array
    and k is the range of the input values.
--> Time Complexity:
    - Best Case: O(n + k)
    - Average Case: O(n + k)
    - Worst Case: O(n + k)
--> Space Complexity: O(k)
    - O(k) for the count array.
    - O(n) for the output array.
--> Adaptive: No
--> Stable: Yes
--> In-Place: No
*/

template<typename T>
void countSort(vector<T>& arr, const int& size){
    if (size == 0) return;

    T maxElement = arr[0];
    for (size_t i = 1; i < size; ++i) {
        if (maxElement < arr[i]) maxElement = arr[i];
    }

    vector<T> result(size, 0);
    vector<int> temp(maxElement +1, 0), prefTemp(maxElement +1, 0);
    for (size_t i = 0; i < size; ++i) {
        temp[arr[i]]++;
    }

    prefTemp[0] = temp[0];
    for (size_t i = 1; i < prefTemp.size(); ++i) {
        prefTemp[i] = prefTemp[i - 1] + temp[i];
    }

    for (int i = size - 1; i >= 0; --i) {
        result[prefTemp[arr[i]] - 1] = arr[i];
        prefTemp[arr[i]]--;
    }

    arr = result;
}

template<typename T>
void countSort(T arr[], const int& size){
    if (size == 0) return;

    T maxElement = arr[0];
    for (size_t i = 1; i < size; ++i) {
        if (maxElement < arr[i]) maxElement = arr[i];
    }

    T* result = new T[size];
    int temp[maxElement +1] = {0}, prefTemp[maxElement +1] = {0};
    for (size_t i = 0; i < size; ++i) {
        temp[arr[i]]++;
    }

    prefTemp[0] = temp[0];
    for (size_t i = 1; i < maxElement +1; ++i) {
        prefTemp[i] = prefTemp[i - 1] + temp[i];
    }

    for (int i = size - 1; i >= 0; --i) {
        result[prefTemp[arr[i]] - 1] = arr[i];
        prefTemp[arr[i]]--;
    }

    for (int i = 0; i < size; ++i) {
        arr[i] = result[i];
    }
    delete[] result;
}

// -------------------------------- MAIN FUNCTION

int main() {
    vector<int> v = {3, 10, 2, 5, 8, 7, 9, 4, 1, 6};
    int vSize = int(v.size());
    int arr[] = {3, 10, 2, 5, 8, 7, 9, 4, 1, 6};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    countSort(v, vSize);
    countSort(arr, arrSize);

    cout << v;
    print(arr, arrSize);
}