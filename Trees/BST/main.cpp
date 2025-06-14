#include <bits/stdc++.h>
#include "BST.h"
using namespace std;

int main() {
    auto *bst = new BST<int>();
    auto *bst2 = new BST<int>();

    // Before adding nodes to the first BST.
    if (bst->isEmpty()) cout << "Tree is Empty..." << endl;
    else cout << "Tree is NOT Empty..." << endl;

    // Adding nodes to the first BST.
    bst->insert(13);
    bst->insert(10);
    bst->insert(25);
    bst->insert(2);
    bst->insert(12);
    bst->insert(20);
    bst->insert(31);
    bst->insert(29);
    bst->insert(28);

    // Adding nodes to the second BST.
    bst2->insert(13);
    bst2->insert(10);
    bst2->insert(25);
    bst2->insert(2);
    bst2->insert(12);
    bst2->insert(20);
    bst2->insert(31);
    bst2->insert(29);
    bst2->insert(28);

    // Count all nodes in the first BST.
    cout << "Number of Nodes: " << bst->countNodes() << endl;

    // Count leaves nodes in the first BST.
    cout << "Number of Leaves: " << bst->countLeaves() << endl;

    // Count internal nodes in the first BST.
    cout << "Number of Internal Nodes: " << bst->countInternalNodes() << endl;

    // Check if the tree is balance after adding nodes.
    if (bst->isBalance()) cout << "The Tree is Balanced..." << endl;
    else cout << "The Tree is NOT Balanced..." << endl;

    // Check if the two trees are the same before deletion of any node.
    if (bst->isSameTree(bst2)) cout << "The two BST are the same..." << endl;
    else cout << "The two BST are NOT the same..." << endl;

    // Delete 12 from the first BST.
    bst->erase(12);

    // Search for 12 in the first BST after deletion.
    if (bst->search(12)) cout << "Found" << endl;
    else cout << "NOT Found" << endl;

    // Check if the two trees are the same after deletion 12 from the first BST.
    if (bst->isSameTree(bst2)) cout << "The two BST are the same..." << endl;
    else cout << "The two BST are NOT the same..." << endl;

    // Find the minimum and maximum elements in the BST.
    cout << "Minimum: " << bst->minElement() << endl;
    cout << "Maximum: " << bst->maxElement() << endl;

    // Print the BST in different orders.
    cout << "Breath First: ";
    bst->printBreadthFirst();

    cout << "Depth First (Inorder Traversal): ";
    bst->printDepthFirst("Inorder Traversal");

    cout << "Depth First (Preorder Traversal): ";
    bst->printDepthFirst("Preorder Traversal");

    cout << "Depth First (Postorder Traversal): ";
    bst->printDepthFirst("Postorder Traversal");

    // Find the sum of all nodes in the BST.
    cout << "Sum of nodes: " << bst->findSum() << endl;

    // Find the height of the BST.
    cout << "The Tree has: " << bst->level() << " levels." << endl;

    // Store levels of the BST in a vector of vectors.
    cout << "Levels of the BST:" << endl;
    vector<vector<int>> arr = bst->storeLevels();
    for (int i = 0; i < arr.size(); ++i) {
        cout << " - Level " << i+1 << ": ";
        for (const int& j : arr[i]) {
            cout << j << " ";
        }
        cout << endl;
    }

    // Clear the BST.
    bst->clear();

    // Count nodes after clearing the tree.
    cout << "Number of Nodes: " << bst->countNodes() << endl;

    // Make a new Balanced BST tree from an array.
    vector<int> array = {5, 3, 8, 1, 4, 7, 6, 2};
    bst->arrayToBalancedBST(array);
    cout << "Balanced BST tree created from an array:" << endl;
    arr = bst->storeLevels();
    for (int i = 0; i < arr.size(); ++i) {
        cout << " - Level " << i+1 << ": ";
        for (const int& j : arr[i]) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}