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

// -------------------------------- MERGE SORT
/*
--> Time Complexity:
    - Best Case: O(nlog(n))
    - Average Case: O(nlog(n))
    - Worst Case: O(nlog(n))
--> Space Complexity: O(n)
--> Adaptive: No
--> Stable: Yes
--> In-Place: No
*/

template<typename T>
void merge(vector<T>& arr, const int left, const int mid, const int right){
    int n1 = mid - left + 1, n2 = right - mid;
    vector<T> L(n1), R(n2);

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j) R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left...right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    // Copy the remaining elements of L[] if there are any.
    while (i < n1) arr[k++] = L[i++];

    // Copy the remaining elements of R[] if there are any.
    while (j < n2) arr[k++] = R[j++];
}

template<typename T>
void mergeSort(vector<T>& arr, int left, int right){
    if (left < right) {
        const int mid = (right + left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

template<typename T>
void merge(T arr[], const int left, const int mid, const int right){
    int n1 = mid - left + 1, n2 = right - mid;

    T* L = new T[n1];
    T* R = new T[n2];

    for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

template<typename T>
void mergeSort(T arr[], int left, int right){
    if (left < right) {
        const int mid = (right + left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// -------------------------------- MAIN FUNCTION

int main() {
    vector<int> v = {3, 10, 2, 5, 8, 7, 9, 4, 1, 6};
    int vSize = int(v.size());
    int arr[] = {3, 10, 2, 5, 8, 7, 9, 4, 1, 6};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    mergeSort(v, 0, vSize - 1);
    mergeSort(arr, 0, arrSize - 1);

    cout << v;
    print(arr, arrSize);
}