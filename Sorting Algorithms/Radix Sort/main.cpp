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

// -------------------------------- RADIX SORT
/*
--> Time Complexity:
    - Best Case: O(n)
    - Average Case: O(n^2)
    - Worst Case: O(n^2)
--> Space Complexity = O(1)
*/

template<typename T>
void countingSortForRadix(vector<T>& arr, const int& size, const int& place){
    const int max = 10;

    vector<T> result(size, 0);
    vector<int> temp(max +1, 0), prefTemp(max +1, 0);
    for (size_t i = 0; i < size; ++i) {
        temp[(arr[i] /place) %10]++;
    }

    prefTemp[0] = temp[0];
    for (size_t i = 1; i < prefTemp.size(); ++i) {
        prefTemp[i] = prefTemp[i - 1] + temp[i];
    }

    for (int i = size - 1; i >= 0; --i) {
        result[prefTemp[(arr[i] /place) %10] - 1] = arr[i];
        prefTemp[(arr[i] /place) %10]--;
    }

    arr = result;
}

template<typename T>
void radixSort(vector<T>& arr, const int& size){
    if (size == 0) return;

    T maxElement = arr[0];
    for (size_t i = 1; i < size; ++i) {
        if (maxElement < arr[i]) maxElement = arr[i];
    }

    for (int place = 1; maxElement /place > 0; place *= 10)
        countingSortForRadix(arr, size, place);
}

template<typename T>
void countingSortForRadix(T arr[], const int& size, const int& place){
    const int max = 10;

    T* result = new T[size];
    int temp[max +1] = {0}, prefTemp[max +1] = {0};
    for (size_t i = 0; i < size; ++i) {
        temp[(arr[i] /place) %10]++;
    }

    prefTemp[0] = temp[0];
    for (size_t i = 1; i < max +1; ++i) {
        prefTemp[i] = prefTemp[i - 1] + temp[i];
    }

    for (int i = size - 1; i >= 0; --i) {
        result[prefTemp[(arr[i] /place) %10] - 1] = arr[i];
        prefTemp[(arr[i] /place) %10]--;
    }

    for (int i = 0; i < size; ++i) {
        arr[i] = result[i];
    }
    delete[] result;
}

template<typename T>
void radixSort(T arr[], const int& size){
    if (size == 0) return;

    T maxElement = arr[0];
    for (size_t i = 1; i < size; ++i) {
        if (maxElement < arr[i]) maxElement = arr[i];
    }

    for (int place = 1; maxElement /place > 0; place *= 10)
        countingSortForRadix(arr, size, place);
}

// -------------------------------- MAIN FUNCTION

int main() {
    vector<int> v = {3, 10, 2, 5, 8, 7, 9, 4, 1, 6};
    int vSize = int(v.size());
    int arr[] = {3, 10, 2, 5, 8, 7, 9, 4, 1, 6};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    radixSort(v, vSize);
    radixSort(arr, arrSize);

    cout << v;
    print(arr, arrSize);
}