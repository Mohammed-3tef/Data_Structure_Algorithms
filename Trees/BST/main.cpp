#include <bits/stdc++.h>
#include "BST.h"
using namespace std;

int main() {
    auto *bst = new BST<int>();

    if (bst->isEmpty()) cout << "Tree is Empty..." << endl;
    else cout << "Tree is NOT Empty..." << endl;

    bst->insert(13);
    bst->insert(10);
    bst->insert(25);
    bst->insert(2);

    bst->insert(12);
    bst->insert(20);
    bst->insert(31);
    bst->insert(29);
    bst->insert(28);

    cout << "Number of Nodes: " << bst->countNodes() << endl;
    cout << "Number of Leaves: " << bst->countLeaves() << endl;
    cout << "Number of Internal Nodes: " << bst->countInternalNodes() << endl;

    if (bst->isBalance()) cout << "The Tree is Balanced..." << endl;
    else cout << "The Tree is NOT Balanced..." << endl;

    bst->erase(12);
    if (bst->search(12)) cout << "Found" << endl;
    else cout << "NOT Found" << endl;

    cout << "Minimum: " << bst->minElement() << endl;
    cout << "Maximum: " << bst->maxElement() << endl;

    cout << "Breath First: ";
    bst->printBreadthFirst();

    cout << "Depth First (Inorder Traversal): ";
    bst->printDepthFirst("Inorder Traversal");

    cout << "Depth First (Preorder Traversal): ";
    bst->printDepthFirst("Preorder Traversal");

    cout << "Depth First (Postorder Traversal): ";
    bst->printDepthFirst("Postorder Traversal");

    cout << "Sum of nodes: " << bst->findSum() << endl;
    cout << "The Tree has: " << bst->level() << " levels." << endl;

    bst->clear();
    cout << "Number of Nodes: " << bst->countNodes() << endl;

    return 0;
}