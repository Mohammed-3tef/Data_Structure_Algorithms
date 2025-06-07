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

    cout << "The last element: " << st->top() << endl;

    st->pop();

    cout << "The last element: " << st->top() << endl;

    cout << "The Stack: ";
    st->print();

    st->clear();

    if (st->empty()) cout << "The Stack is empty..." << endl;
    else cout << "The Stack is NOT empty..." << endl;

    cout << endl;

    string parentheses = "([)]";
    if (isValidParentheses(parentheses)) cout << parentheses << " is valid" << endl;
    else cout << parentheses << " is not valid" << endl;

    cout << endl;

    string postfixExpression = "5 1 2 + 4 * + 3 -";
    cout << "The Result = " << evaluatePostfix(postfixExpression) << endl;

    cout << endl;

    string infixExpression = "3 + 2 * 5";
    postfixExpression = infixToPostfix(infixExpression);
    cout << "The Postfix Expression is: " << postfixExpression << endl;
    cout << "The Result = " << evaluatePostfix(postfixExpression) << endl;

    cout << endl;

    auto *q = new Queue<int>();
    q->enqueue(10);
    q->enqueue(15);
    q->enqueue(5);
    q->enqueue(20);

    cout << "The Queue: ";
    q->print();

    cout << "Minimum: " << q->findMin() << endl;
    cout << "Maximum: " << q->findMax() << endl;
    cout << "The first element: " << q->front() << endl;
    cout << "The last element: " << q->back() << endl;

    q->dequeue();

    cout << "The Queue: ";
    q->print();

    q->clear();

    if (q->empty()) cout << "The Queue is empty..." << endl;
    else cout << "The Queue is NOT empty..." << endl;

    return 0;
}