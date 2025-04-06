#include <bits/stdc++.h>
#include "Stack.h"
#include "Queue.h"
using namespace std;

int main() {

    auto *st = new Stack<int>();
    st->push(2);
    st->push(1);
    st->push(3);
    st->push(5);
    st->push(4);

    cout << st->top() << endl;
    st->pop();
    cout << st->top() << endl;

    st->print();
    st->clear();

    auto *q = new Queue<int>();
    q->enqueue(10);
    q->enqueue(15);
    q->enqueue(5);
    q->enqueue(20);
    q->print();

    cout << q->findMin() << " " << q->findMax() << endl;
    cout << q->front() << " " << q->back() << endl;

    q->dequeue();
    q->print();

    q->clear();

    if (q->isEmpty()) cout << "The Queue is empty..." << endl;
    else cout << "The Queue is NOT empty..." << endl;

    return 0;
}