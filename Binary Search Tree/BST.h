#ifndef BINARY_SEARCH_TREE_BST_H
#define BINARY_SEARCH_TREE_BST_H

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
protected:
    BSTNode<T>* root;
    int size;
public:
    BST(){
        this->root = 0;
        this->size = 0;
    }

    ~BST(){
        delete this->root;
    }

    void clear(){
        this->root = 0;
        this->size = 0;
    }

    bool isEmpty(){
        return (this->root == 0);
    }

    int length(){
        return this->size;
    }

    T findMin(){
        BSTNode<T>* current = this->root;

        while (current->getLeft() != 0) {
            current = current->getLeft();
        }
        return current->getData();
    }

    T findMax(){
        BSTNode<T>* current = this->root;

        while (current->getRight() != 0) {
            current = current->getRight();
        }
        return current->getData();
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
            this->size++;
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
        this->size++;
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

            this->size--;
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

    void inOrder(BSTNode<T>* current){
        if (current != 0){
            inOrder(current->getLeft());
            cout << current->getData() << " ";
            inOrder(current->getRight());
        }
    }

    void preOrder(BSTNode<T>* current){
        if (current != 0){
            cout << current->getData() << " ";
            preOrder(current->getLeft());
            preOrder(current->getRight());
        }
    }

    void postOrder(BSTNode<T>* current){
        if (current != 0){
            postOrder(current->getLeft());
            postOrder(current->getRight());
            cout << current->getData() << " ";
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

#endif //BINARY_SEARCH_TREE_BST_H