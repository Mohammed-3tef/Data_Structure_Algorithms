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

// -------------------------------- SHELL SORT
/*
--> Time Complexity:
    - Best Case: O(nlog(n))
    - Average Case: O(n^1.5) Depending on gap sequence
    - Worst Case: O(n^2)
--> Space Complexity: O(1)
--> Adaptive: No
--> Stable: No
--> In-Place: Yes
*/

template<typename T>
void shellSort(vector<T>& arr, const int& size) {
    if (size == 0) return;

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

template<typename T>
void shellSort(T arr[], const int& size) {
    if (size == 0) return;

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

// -------------------------------- MAIN FUNCTION

int main() {
    vector<int> v = {3, 10, 2, 5, 8, 7, 9, 4, 1, 6};
    int vSize = int(v.size());
    int arr[] = {3, 10, 2, 5, 8, 7, 9, 4, 1, 6};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    shellSort(v, vSize);
    shellSort(arr, arrSize);

    cout << v;
    print(arr, arrSize);
}