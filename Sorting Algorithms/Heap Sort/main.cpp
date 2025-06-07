#include <bits/stdc++.h>
#define ll long long
#define all(x) (x).begin(), (x).end()                       // Sort From The Beginning.
#define rall(x) (x).rbegin(), (x).rend()                    // Sort From The End.
#define sz(x) (x).size()                                    // Return The Size.
#define no cout << "NO" << endl;
#define yes cout << "YES" << endl;
using namespace std;

void speed_up() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
}

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

template<typename T>
void maxHeapify(T arr[], const int& arrSize, const int& index){
    int left = (2 * index) + 1;
    int right = (2 * index) + 2;
    int max = index;

    if (left < arrSize && arr[left] > arr[max]) max = left;
    else if (right < arrSize && arr[right] > arr[max]) max = right;

    if (max != index){
        swap(arr[index], arr[max]);
        maxHeapify(arr, arrSize, max);
    }
}

template<typename T>
void buildHeap(T arr[], const int& n){
    for (int i = n/2 -1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

template<typename T>
void heapSort(T arr[], const int& n){
    buildHeap(arr, n);
    for (int i = n-1; i > 0; i--) {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

int main() {
    vector<int> v = {3, 10, 2, 5, 8, 7, 9, 4, 1, 6};
    int vSize = int(v.size());
    int arr[] = {3, 10, 2, 5, 8, 7, 9, 4, 1, 6};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

//    heapSort(v, vSize);
    heapSort(arr, arrSize);

    cout << v;
    print(arr, arrSize);
    return 0;
}