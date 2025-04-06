#include <bits/stdc++.h>
#include "BST.h"
using namespace std;

int main() {
    auto* tree = new BST<int>();
    if (tree->isEmpty()) cout << "Tree is Empty..." << endl;
    else cout << "Tree is NOT Empty..." << endl;

    tree->insert(13);
    tree->insert(10);
    tree->insert(25);
    tree->insert(2);

    tree->insert(12);
    tree->insert(20);
    tree->insert(31);
    tree->insert(29);

    cout << "Size -> " << tree->length() << endl;

    tree->erase(12);
    if (tree->search(12)) cout << "Found" << endl;
    else cout << "NOT Found" << endl;

    cout << tree->findMin() << " " << tree->findMax() << endl;

    tree->printBreadthFirst();

    tree->erase(25);

    tree->printDepthFirst("Inorder Traversal");
    tree->printDepthFirst("Preorder Traversal");
    tree->printDepthFirst("Postorder Traversal");

    tree->clear();
    cout << "Size -> " << tree->length() << endl;
}