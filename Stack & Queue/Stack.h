#ifndef STACK_QUEUE_STACK_H
#define STACK_QUEUE_STACK_H

#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Stack {
private:
    T* arr;
    int size;
public:
    Stack(){
        this->size = 0;
        this->arr = new T(this->size) ;
    };

    bool empty(){
        return (this->size == 0) ;
    }

    void clear(){
        this->size = 0;
    }

    T top() const {
        return arr[size - 1];
    };

    void pop(){
        T* newArr = new T(this->size -1);
        for (int i = 0; i < this->size -1; ++i) {
            newArr[i] = this->arr[i];
        }

        delete[] this->arr;
        this->arr = newArr;
        this->size--;
    };

    void push(const T& element){
        T* newArr = new T(this->size + 1);
        for (int i = 0; i < this->size ; ++i) {
            newArr[i] = this->arr[i];
        }

        newArr[this->size] = element;
        delete[] this->arr;
        this->arr = newArr;
        this->size++;
    };

    void print(){
        for (int i = this->size -1; i >= 0; --i) {
            cout << this->arr[i] << " \n"[i == 0];
        }
    }
};

bool isValidParentheses(const string& str){
    stack<char> st;
    for (char i : str) {
        if (i == '(' || i == '[' || i == '{') st.push(i);
        else {
            if (st.empty()) return false;
            else if ((st.top() == '(' && i == ')') ||
                     (st.top() == '[' && i == ']') ||
                     (st.top() == '{' && i == '}')) {
                st.pop();
            }
            else return false;
        }
    }

    if (st.empty()) return true;
    return false;
}

int precedence(char symbol) {
    switch (symbol) {
        case '^': return 3;
        case '*': case '/': return 2;
        case '+': case '-': return 1;
        default: return 0;
    }
}

string infixToPostfix(const string& infix){
    stack<char> st;
    string res;

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        if (isspace(c)) continue;

        if (c >= '0' && c <= '9'){
            res += c;
            res += " ";
        }

        else if (c == '(')
            st.push('(');

        else if (c == ')') {
            while (st.top() != '(') {
                res += st.top();
                res += " ";
                st.pop();
            }
            st.pop();
        }

        else {
            while (!st.empty() && precedence(c) <= precedence(st.top())) {
                res += st.top();
                res += " ";
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        res += st.top();
        res += " ";
        st.pop();
    }

    return res;
}

int evaluatePostfix(const string& postfix){
    stack<int> st;
    int i = 0;
    for (; i < postfix.size(); ++i) {
        string temp;
        while (isdigit(postfix[i])){
            temp += postfix[i++];
        }

        if (!temp.empty()) st.push(stoi(temp));

        int op1 = 0, op2 = 0;
        if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/'){
            op2 = st.top();
            st.pop();

            op1 = st.top();
            st.pop();

            if (postfix[i] == '+') st.push(op1 + op2);
            else if (postfix[i] == '-') st.push(op1 - op2);
            else if (postfix[i] == '*') st.push(op1 * op2);
            else if (postfix[i] == '/') st.push(op1 / op2);
        }
    }
    return st.top();
}

#endif //STACK_QUEUE_STACK_H
