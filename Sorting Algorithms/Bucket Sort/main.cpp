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

// -------------------------------- INSERTION SORT
/*
--> Time Complexity:
    - Best Case: O(n)
    - Average Case: O(n^2)
    - Worst Case: O(n^2)
--> Space Complexity = O(1)
*/

template<typename T>
void insertionSort(vector<T>& arr, const int& size) {
    if (size == 0) return;

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

template<typename T>
void insertionSort(T arr[], const int& size) {
    if (size == 0) return;

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

// -------------------------------- BUCKET SORT
/*
--> Time Complexity:
    - Best Case: O(n)
    - Average Case: O(n^2)
    - Worst Case: O(n^2)
--> Space Complexity = O(1)
*/

template<typename T>
void bucketSort(vector<T>& arr, const int& size){
    T minimum = (arr[0]), maximum = (arr[0]);
    for (int i = 0; i < size; ++i) {
        T val = (arr[i]);
        if (val > maximum) maximum = val;
        if (val < minimum) minimum = val;
    }

    // 2D arrays store buckets, each bucket has a specific range of values.
    vector<vector<T>> buckets(size, vector<T>());
    vector<int> bucket_sizes(size, 0);

    if (minimum == maximum) return;

    for (int i = 0; i < size; ++i) {
        // Calculate the normalization factor to determine the bucket index
        T norm = (arr[i] - minimum) / (maximum - minimum);
        int index = static_cast<int>(norm * (size - 1)); // Determine bucket index

        // Store the value in the corresponding bucket
        buckets[index].push_back(arr[i]);
        bucket_sizes[index]++;
    }

    // Sort each bucket's value by insertion sort.
    int index;
    for (int i = 0; i < size; ++i) {
        if (bucket_sizes[i] > 0) {
            insertionSort(buckets[i], bucket_sizes[i]);
        }
    }

    // Return again the values in original Array
    index = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < bucket_sizes[i]; ++j) {
            arr[index++] = buckets[i][j];
        }
    }
}

template<typename T>
void bucketSort(T arr[], const int& size){
    T minimum = (arr[0]), maximum = (arr[0]);
    for (int i = 0; i < size; ++i) {
        T val = (arr[i]);
        if (val > maximum) maximum = val;
        if (val < minimum) minimum = val;
    }

    // 2D arrays store buckets, each bucket has a specific range of values.
    T **buckets = new T *[size];
    // array follow indexes for each bucket.
    int *bucket_sizes = new int[size];
    // initialize the buckets and their indexes.
    for (int i = 0; i < size; ++i) {
        buckets[i] = new T[size];
        bucket_sizes[i] = 0;
    }

    if (minimum == maximum) return;

    for (int i = 0; i < size; ++i) {
        // Calculate the Normalization that uses to determine the index and the bucket which has the value.
        T norm = (arr[i] - minimum) / (maximum - minimum);
        // Calculate the index by Normalization.
        int index = static_cast<int>(norm * (size - 1));
        // store the value in its bucket
        buckets[index][bucket_sizes[index]] = arr[i];
        bucket_sizes[index]++;
    }

    // Sort each bucket's value by insertion sort.
    int index = 1;
    for (int i = 0; i < size; ++i) {
        if (bucket_sizes[i] > 0) {
            insertionSort(buckets[i], bucket_sizes[i]);
        }
    }

    // Return again the values in original Array
    index = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < bucket_sizes[i]; ++j) {
            arr[index++] = buckets[i][j];
        }
    }

    for (int i = 0; i < size; ++i) {
        delete[] buckets[i];
    }
    delete[] buckets;
    delete[] bucket_sizes;
}

// -------------------------------- MAIN FUNCTION

int main() {
    vector<int> v = {3, 10, 2, 5, 8, 7, 9, 4, 1, 6};
    int vSize = int(v.size());
    int arr[] = {3, 10, 2, 5, 8, 7, 9, 4, 1, 6};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    bucketSort(v, vSize);
    bucketSort(arr, arrSize);

    cout << v;
    print(arr, arrSize);
}