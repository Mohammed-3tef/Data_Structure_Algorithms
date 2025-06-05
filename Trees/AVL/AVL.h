#ifndef AVL_AVL_H
#define AVL_AVL_H

#include <bits/stdc++.h>
using namespace std;

template<typename T>
class AVLNode{
private:
    T data;
    AVLNode<T> *left, *right;
    int height;
public:
    AVLNode(){
        this->left = 0;
        this->right = 0;
        this->height = 1;
    }

    explicit AVLNode(T data, AVLNode<T> *left = 0, AVLNode<T> *right = 0, int height = 1){
        this->data = data;
        this->left = left;
        this->right = right;
        this->height = height;
    }

    AVLNode<T>* getLeft() const {return this->left;}
    void setLeft(AVLNode<T>* newLeft) {this->left = newLeft;}

    AVLNode<T>* getRight() const {return this->right;}
    void setRight(AVLNode<T> *newRight) {this->right = newRight;}

    T getData() const {return this->data;}
    void setData(const T& newData) {this->data = newData;}

    int getHeight() const {return this->height;}
    void setHeight(const int& newHeight) {this->height = newHeight;}
};

template<typename T>
class AVL {
private:
    AVLNode<T>* root;

    bool isSame(AVLNode<T>* left, AVLNode<T>* right) {
        if (!left && !right) return true;
        else if (!left || !right) return false;
        return (left->getData() == right->getData()) &&
               isSame(left->getLeft(), right->getLeft()) &&
               isSame(left->getRight(), right->getRight());
    }

    int findHeight(AVLNode<T>* current) {
        if (!current) return 0;
        return current->getHeight();
    }

    int balanceFactor(AVLNode<T>* current) {
        if (!current) return 0;
        return findHeight(current->getLeft()) - findHeight(current->getRight());
    }

    void updateHeight(AVLNode<T>* current) {
        if (current) {
            current->setHeight(1 + max(findHeight(current->getLeft()), findHeight(current->getRight())));
        }
    }

    void inOrder(AVLNode<T>* current){
        if (current){
            inOrder(current->getLeft());
            cout << current->getData() << " ";
            inOrder(current->getRight());
        }
    }

    void inOrder(AVLNode<T>* current, const string& action, T& result){
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

    void preOrder(AVLNode<T>* current){
        if (current){
            cout << current->getData() << " ";
            preOrder(current->getLeft());
            preOrder(current->getRight());
        }
    }

    void postOrder(AVLNode<T>* current){
        if (current ){
            postOrder(current->getLeft());
            postOrder(current->getRight());
            cout << current->getData() << " ";
        }
    }

    AVLNode<T>* rotateRight(AVLNode<T>* y) {
        AVLNode<T>* leftChild = y->getLeft();
        AVLNode<T>* T2 = leftChild->getRight();

        leftChild->setRight(y);
        y->setLeft(T2);

        updateHeight(y);
        updateHeight(leftChild);

        return leftChild;
    }

    AVLNode<T>* rotateLeft(AVLNode<T>* x) {
        AVLNode<T>* rightChild = x->getRight();
        AVLNode<T>* T2 = rightChild->getLeft();

        rightChild->setLeft(x);
        x->setRight(T2);

        updateHeight(x);
        updateHeight(rightChild);

        return rightChild;
    }

    AVLNode<T>* updateBalance(AVLNode<T>* current) {
        updateHeight(current);
        int balance = balanceFactor(current);

        // Left heavy
        if (balance > 1) {
            if (balanceFactor(current->getLeft()) < 0)
                current->setLeft(rotateLeft(current->getLeft()));
            return rotateRight(current);
        }

        // Right heavy
        if (balance < -1) {
            if (balanceFactor(current->getRight()) > 0)
                current->setRight(rotateRight(current->getRight()));
            return rotateLeft(current);
        }

        return current;
    }

    AVLNode<T>* insertNode(AVLNode<T>* node, const T& data) {
        if (!node) return new AVLNode<T>(data);
        if (data < node->getData())
            node->setLeft(insertNode(node->getLeft(), data));
        else if (data > node->getData())
            node->setRight(insertNode(node->getRight(), data));
        else return node;

        return updateBalance(node);
    }

    AVLNode<T>* eraseNode(AVLNode<T>* node, const T& data) {
        if (!node) return nullptr;

        if (data < node->getData())
            node->setLeft(eraseNode(node->getLeft(), data));
        else if (data > node->getData())
            node->setRight(eraseNode(node->getRight(), data));
        else {
            if (!node->getLeft() || !node->getRight()) {
                AVLNode<T>* temp = node->getLeft() ? node->getLeft() : node->getRight();
                delete node;
                return temp;
            } else {
                AVLNode<T>* maxNode = findMax(node->getLeft());
                node->setData(maxNode->getData());
                node->setLeft(eraseNode(node->getLeft(), maxNode->getData()));
            }
        }

        return updateBalance(node);
    }

    AVLNode<T>* findMin(AVLNode<T>* node) {
        while (node->getLeft()) node = node->getLeft();
        return node;
    }

    AVLNode<T>* findMax(AVLNode<T>* node) {
        while (node->getRight()) node = node->getRight();
        return node;
    }

    void destroyTree(AVLNode<T>* node) {
        if (node) {
            destroyTree(node->getLeft());
            destroyTree(node->getRight());
            delete node;
        }
    }

public:
    AVL(){
        this->root = 0;
    }

    ~AVL() {
        destroyTree(this->root);
    }

    void clear(){
        destroyTree(this->root);
        this->root = 0;
    }

    bool empty(){
        return (this->root == 0);
    }

    bool isSameTree(AVL<T>* other){
        if (!this->root && !other->root) return true;
        else if (!this->root || !other->root || this->root->getData() != other->root->getData()) return false;
        return isSame(this->root->getLeft(), other->root->getLeft()) && isSame(this->root->getRight(), other->root->getRight());
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
        return findMin(this->root)->getData();
    }

    T maxElement(){
        return findMax(this->root)->getData();
    }

    T findSum(){
        T sum = 0;
        inOrder(this->root, "Sum", sum);
        return sum;
    }

    bool search(const T& data){
        AVLNode<T>* current = this->root;

        while (current != 0) {
            if (current->getData() == data)
                return true;
            else if (current->getData() < data)
                current = current->getRight();
            else current = current->getLeft();
        }
        return false;
    }

    void insert(const T& data) {
        this->root = insertNode(this->root, data);
    }

    void erase(const T& data) {
        this->root = eraseNode(this->root, data);
    }

    void printBreadthFirst(){
        AVLNode<T>* current = this->root;
        queue<AVLNode<T>*> queue;

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
        AVLNode<T>* current = this->root;

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

#endif //AVL_AVL_H