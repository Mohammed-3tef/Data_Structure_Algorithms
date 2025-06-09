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

// -------------------------------- QUICK SORT
/*
--> Time Complexity:
    - Best Case: O(nlog(n))
    - Average Case: O(nlog(n))
    - Worst Case: O(n^2)
--> Space Complexity: O(log(n))
--> Adaptive: No
--> Stable: No
--> In-Place: Yes

--> Pivot Selection:
    - First Element (Not good for sorted arrays).
    - Last Element (Ok).
    - Random Element (Best Way).
    - Median of Three (first, middle, last).
*/

template<typename T>
int partition (vector<T>& arr, int left, int right){
    T pivot = arr[left];        // Choosing the first element as a pivot.
    int i = left;
    for (int j = left +1; j <= right; j++) {
        if (arr[j] < pivot) swap(arr[j], arr[++i]);
    }
    swap(arr[left], arr[i]);
    return i;
}

template<typename T>
void quickSort(vector<T>& arr, const int& left, const int& right){
    if (left < right) {
        const int mid = partition(arr, left, right);
        quickSort(arr, left, mid - 1);
        quickSort(arr, mid + 1, right);
    }
}

template<typename T>
int partition (T arr[], int left, int right){
    T pivot = arr[left];        // Choosing the first element as a pivot.
    int i = left;
    for (int j = left +1; j <= right; j++) {
        if (arr[j] < pivot) swap(arr[j], arr[++i]);
    }
    swap(arr[left], arr[i]);
    return i;
}

template<typename T>
void quickSort(T arr[], const int& left, const int& right){
    if (left < right) {
        const int mid = partition(arr, left, right);
        quickSort(arr, left, mid - 1);
        quickSort(arr, mid + 1, right);
    }
}

// -------------------------------- MAIN FUNCTION

int main() {
    vector<int> v = {3, 10, 2, 5, 8, 7, 9, 4, 1, 6};
    int vSize = int(v.size());
    int arr[] = {3, 10, 2, 5, 8, 7, 9, 4, 1, 6};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    quickSort(v, 0, vSize - 1);
    quickSort(arr, 0, arrSize - 1);

    cout << v;
    print(arr, arrSize);
}