#include <bits/stdc++.h>
#include "AVL.h"
using namespace std;

int main() {
    auto* avl = new AVL<int>();
    auto* avl2 = new AVL<int>();

    // Check if the first AVL tree is empty before adding nodes.
    if (avl->empty()) cout << "Tree is Empty..." << endl;
    else cout << "Tree is NOT Empty..." << endl;

    // Adding nodes to the first AVL tree.
    avl->insert(13);
    avl->insert(10);
    avl->insert(25);
    avl->insert(2);
    avl->insert(12);
    avl->insert(20);
    avl->insert(31);
    avl->insert(29);
    avl->insert(28);

    // Adding nodes to the second AVL tree.
    avl2->insert(13);
    avl2->insert(10);
    avl2->insert(25);
    avl2->insert(2);
    avl2->insert(12);
    avl2->insert(20);
    avl2->insert(31);
    avl2->insert(29);
    avl2->insert(28);

    // Count all nodes in the first AVL tree.
    cout << "Number of Nodes: " << avl->countNodes() << endl;

    // Count leaves nodes in the first AVL tree.
    cout << "Number of Leaves: " << avl->countLeaves() << endl;

    // Count internal nodes in the first AVL tree.
    cout << "Number of Internal Nodes: " << avl->countInternalNodes() << endl;

    // Check the two AVL trees are the same before deletion of any node.
    if(avl->isSameTree(avl2)) cout << "The two AVL trees are the same..." << endl;
    else cout << "The two AVL trees are NOT the same..." << endl;

    // Delete 12 from the first AVL tree.
    avl->erase(12);

    // Search for 12 in the first AVL tree after deletion.
    if (avl->search(12)) cout << "Found" << endl;
    else cout << "NOT Found" << endl;

    // Check the two AVL trees are the same after deletion of 12 from the first AVL tree.
    if(avl->isSameTree(avl2)) cout << "The two AVL trees are the same..." << endl;
    else cout << "The two AVL trees are NOT the same..." << endl;

    // Find the minimum and maximum elements in the AVL tree.
    cout << "Minimum: " << avl->minElement() << endl;
    cout << "Maximum: " << avl->maxElement() << endl;

    // Print the AVL tree in Inorder, Preorder, and Postorder traversals.
    cout << "Breath First: ";
    avl->printBreadthFirst();

    cout << "Depth First (Inorder Traversal): ";
    avl->printDepthFirst("Inorder Traversal");

    cout << "Depth First (Preorder Traversal): ";
    avl->printDepthFirst("Preorder Traversal");

    cout << "Depth First (Postorder Traversal): ";
    avl->printDepthFirst("Postorder Traversal");

    // Find the sum of all nodes in the AVL tree.
    cout << "Sum of nodes: " << avl->findSum() << endl;

    // Find the height of the AVL tree.
    cout << "The tree has: " << avl->level() << " levels" << endl;

    // Clear the AVL tree.
    avl->clear();

    // Count all nodes in the AVL tree after clearing it.
    cout << "Number of Nodes: " << avl->countNodes() << endl;

    return 0;
}