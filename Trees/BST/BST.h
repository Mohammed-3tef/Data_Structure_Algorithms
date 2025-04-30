#ifndef BST_BST_H
#define BST_BST_H

#include <bits/stdc++.h>
using namespace std;

template<typename T>
class BSTNode{
private:
    T data;
    BSTNode *left, *right;
public:
    BSTNode(){
        this->left = 0;
        this->right = 0;
    }

    explicit BSTNode(T data, BSTNode *left = 0, BSTNode *right = 0){
        this->data = data;
        this->left = left;
        this->right = right;
    }

    T getData(){return this->data;}
    void setData(const T& newData){this->data = newData;}

    BSTNode* getRight(){return this->right;}
    void setRight(BSTNode<T> *node){this->right = node;}

    BSTNode* getLeft(){return this->left;}
    void setLeft(BSTNode<T>* node){this->left = node;}
};

template<typename T>
class BST {
private:
    BSTNode<T>* root;

    int findHeight(BSTNode<T>* current){
        if (!current) return -1;
        return 1 + max(findHeight(current->getLeft()), findHeight(current->getRight()));
    }

    int balanceFactor(BSTNode<T>* current){
        if (!current) return 0;
        return findHeight(current->getLeft()) - findHeight(current->getRight());
    }

    void inOrder(BSTNode<T>* current){
        if (current){
            inOrder(current->getLeft());
            cout << current->getData() << " ";
            inOrder(current->getRight());
        }
    }

    void inOrder(BSTNode<T>* current, const string& action, T& result){
        if (current){
            inOrder(current->getLeft(), action, result);

            if (action == "Sum") result += current->getData();
            else if (action == "Count Nodes") result++;
            else if (action == "Count Leaves"){
                if (!current->getLeft() && !current->getRight()) result++;
            }
            else if (action == "Balance") {
                int balanceFac = balanceFactor(current);
                if (balanceFac != 0 && balanceFac != 1 && balanceFac != -1) {
                    result = false;
                    return;
                }
            }

            inOrder(current->getRight(), action, result);
        }
    }

    void preOrder(BSTNode<T>* current){
        if (current){
            cout << current->getData() << " ";
            preOrder(current->getLeft());
            preOrder(current->getRight());
        }
    }

    void postOrder(BSTNode<T>* current){
        if (current){
            postOrder(current->getLeft());
            postOrder(current->getRight());
            cout << current->getData() << " ";
        }
    }

public:
    BST(){
        this->root = 0;
    }

    ~BST(){
        delete this->root;
    }

    void clear(){
        this->root = 0;
    }

    bool isEmpty(){
        return (this->root == 0);
    }

    bool isBalance(){
        T balance = true;
        inOrder(this->root, "Balance", balance);
        return balance;
    }

    int level(){
        return findHeight(this->root);
    }

    int countNodes(){
        T totalNodes = 0;
        inOrder(this->root, "Count Nodes", totalNodes);
        return totalNodes;
    }

    int countLeaves(){
        T totalLeaves = 0;
        inOrder(this->root, "Count Leaves", totalLeaves);
        return totalLeaves;
    }

    int countInternalNodes(){
        return countNodes() - countLeaves();
    }

    T minElement(){
        BSTNode<T>* current = this->root;

        while (current->getLeft() != 0) {
            current = current->getLeft();
        }
        return current->getData();
    }

    T maxElement(){
        BSTNode<T>* current = this->root;

        while (current->getRight() != 0) {
            current = current->getRight();
        }
        return current->getData();
    }

    T findSum(){
        T sum = 0;
        inOrder(this->root, "Sum", sum);
        return sum;
    }

    bool search(const T& data){
        BSTNode<T>* current = this->root;

        while (current != 0) {
            if (current->getData() == data)
                return true;
            else if (current->getData() < data)
                current = current->getRight();
            else current = current->getLeft();
        }
        return false;
    }

    void insert(const T& data){
        auto* newNode = new BSTNode<T>(data);

        if (this->root == 0) {
            this->root = newNode;
            return;
        }

        BSTNode<T>* current = this->root;

        while (true) {
            if (data < current->getData()) {
                if (current->getLeft() == 0) {
                    current->setLeft(newNode);
                    break;
                }
                current = current->getLeft();
            }
            else if (data > current->getData()) {
                if (current->getRight() == 0) {
                    current->setRight(newNode);
                    break;
                }
                current = current->getRight();
            }
            else {
                delete newNode;
                break;
            }
        }
    }

    void erase(const T& data){
        BSTNode<T>* node = this->root;
        BSTNode<T>* parent = nullptr;

        while (node != 0) {
            if (node->getData() == data) break;

            parent = node;
            if (node->getData() < data)
                node = node->getRight();
            else
                node = node->getLeft();
        }

        if (node != 0) {
            // Case 1: Node has two children
            if (node->getLeft() && node->getRight()) {
                BSTNode<T>* temp = node->getLeft();
                BSTNode<T>* prev = node;

                while (temp->getRight() != 0) {
                    prev = temp;
                    temp = temp->getRight();
                }

                node->setData(temp->getData());

                // Remove the predecessor node
                if (prev == node)
                    prev->setLeft(temp->getLeft());
                else
                    prev->setRight(temp->getLeft());

                delete temp;
            }
                // Case 2: Node has only one child or no child
            else {
                BSTNode<T>* child = (node->getLeft()) ? node->getLeft() : node->getRight();

                if (!parent) this->root = child; // Deleting the root node
                else if (parent->getLeft() == node)
                    parent->setLeft(child);
                else
                    parent->setRight(child);

                delete node;
            }
        }
    }

    void printBreadthFirst(){
        BSTNode<T>* current = this->root;
        queue<BSTNode<T>*> queue;

        if (current != 0){
            queue.push(current);
            while (!queue.empty()){
                current = queue.front();
                cout << current->getData() << " ";
                queue.pop();

                if (current->getLeft() != 0)
                    queue.push(current->getLeft());
                if (current->getRight() != 0)
                    queue.push(current->getRight());
            }
            cout << endl;
        }
    }

    void printDepthFirst(const string& orderBy = "Inorder Traversal"){
        BSTNode<T>* current = this->root;

        if (current != 0){
            if (orderBy == "Inorder Traversal"){
                inOrder(current);
                cout << endl;
            }
            else if (orderBy == "Preorder Traversal"){
                preOrder(current);
                cout << endl;
            }
            else if (orderBy == "Postorder Traversal"){
                postOrder(current);
                cout << endl;
            }
        }
    }
};

#endif //BST_BST_H
