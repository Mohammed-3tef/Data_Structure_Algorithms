#include <bits/stdc++.h>
#include "AVL.h"
using namespace std;

int main() {

    auto* avl = new AVL<int>();

    if (avl->empty()) cout << "Tree is Empty..." << endl;
    else cout << "Tree is NOT Empty..." << endl;

    avl->insert(13);
    avl->insert(10);
    avl->insert(25);
    avl->insert(2);

    avl->insert(12);
    avl->insert(20);
    avl->insert(31);
    avl->insert(29);
    avl->insert(28);

    cout << "Number of Nodes: " << avl->countNodes() << endl;
    cout << "Number of Leaves: " << avl->countLeaves() << endl;
    cout << "Number of Internal Nodes: " << avl->countInternalNodes() << endl;

    avl->erase(12);
    if (avl->search(12)) cout << "Found" << endl;
    else cout << "NOT Found" << endl;

    cout << "Minimum: " << avl->minElement() << endl;
    cout << "Maximum: " << avl->maxElement() << endl;

    cout << "Breath First: ";
    avl->printBreadthFirst();

    cout << "Depth First (Inorder Traversal): ";
    avl->printDepthFirst("Inorder Traversal");

    cout << "Depth First (Preorder Traversal): ";
    avl->printDepthFirst("Preorder Traversal");

    cout << "Depth First (Postorder Traversal): ";
    avl->printDepthFirst("Postorder Traversal");

    cout << "Sum of nodes: " << avl->findSum() << endl;
    cout << "The tree has: " << avl->level() << " levels" << endl;

    avl->clear();
    cout << "Number of Nodes: " << avl->countNodes() << endl;

    return 0;
}