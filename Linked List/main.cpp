#include <bits/stdc++.h>
#include "Linked_List.h"
using namespace std;

template<typename T>
void operator<<(ostream &out, vector<T> &arr) {
    for (auto i: arr) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    auto list = new LinkedList<int>;

    list->insert(10);
    list->insert(5);
    list->insert(50);

    auto n1 = list->front();
//    n1->printNode();

    list->insert(15);
    list->insert(55);

    auto n2 = list->back();
    auto n3 = list->get(1);
//    n2->printNode();
//    n3->printNode();

    list->print();
    cout << endl;

    list->deleteByValue(0);
    list->deleteByIndex(6);

    list->print();
    cout << endl;



    return 0;
}