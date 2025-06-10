#ifndef BST_PROBLEM_SOLVING_H
#define BST_PROBLEM_SOLVING_H

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    bool isMirror(TreeNode* left, TreeNode* right){
        if (!left && !right) return true;
        else if (!left || !right) return false;
        return (left->val == right->val) && isMirror(left->right, right->left) && isMirror(left->left, right->right);
    }

    bool isSame(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;
        else if (!left || !right) return false;
        return (left->val == right->val) &&
               isSame(left->left, right->left) &&
               isSame(left->right, right->right);
    }

    void inorder(TreeNode *current, vector<int> &res){
        if (current){
            inorder(current->left, res);
            res.push_back(current->val);
            inorder(current->right, res);
        }
    }

    void inorder(Node *current, vector<int> &res){
        if (current){
            inorder(current->left, res);
            res.push_back(current->data);
            inorder(current->right, res);
        }
    }

    void inorder(TreeNode *current, map<int, int> &mp){
        if (current){
            inorder(current->right, mp);
            mp[current->val]++;
            inorder(current->left, mp);
        }
    }

public:
    /*
        * 230. Kth Smallest Element in a BST (Leetcode).
        * Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
    */
    int kthSmallest(TreeNode* root, int k) {
        vector<int> vec;
        inorder(root, vec);
        sort(vec.begin(), vec.end());
        return vec[k-1];
    }

    /*
        * Median of BST (Geeks for Geeks).
        * Link: https://www.geeksforgeeks.org/problems/median-of-bst/1?page=1&category=Binary%20Search%20Tree&difficulty=Easy&sortBy=submissions
    */
    float findMedian(struct Node *root) {
        vector<int> vec;
        inorder(root, vec);
        sort(vec.begin(), vec.end());
        int midIndex = vec.size() /2;
        if (vec.size() %2 == 0) return float((vec[midIndex - 1] + vec[midIndex])) /2;
        return vec[midIndex];
    }

    /*
        * 501. Find Mode in Binary Search Tree (Leetcode).
        * Link: https://leetcode.com/problems/find-mode-in-binary-search-tree/description/
    */
    vector<int> findMode(TreeNode* root) {
        map<int, int> mode;
        inorder(root, mode);
        vector<pair<int, int>> vec;
        for(auto m : mode){
            vec.emplace_back(m);
        }
        vector<int> res;
        sort(vec.begin(), vec.end(), [](const pair<int, int> a, pair<int, int> b){
            return a.second > b.second;
        });

        res.push_back(vec[0].first);
        for (int i = 1; i < vec.size(); ++i) {
            if (vec[i].second != vec[0].second) break;
            res.push_back(vec[i].first);
        }

        return res;
    }

    /*
        * 783. Minimum Distance Between BST Nodes (Leetcode).
        * Link: https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/
    */
    int minDiffInBST(TreeNode* root) {
        vector<int> vec, res;
        inorder(root, vec);
        for (int i = 0; i < vec.size(); ++i) {
            for (int j = i+1; j < vec.size(); ++j) {
                res.push_back(abs(vec[i] - vec[j]));
            }
        }
        sort(res.begin(), res.end());
        return res[0];
    }

    /*
        * 530. Minimum Absolute Difference in BST (Leetcode).
        * Link: https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/
    */
    int getMinimumDifference(TreeNode* root) {
        vector<int> vec, res;
        inorder(root, vec);
        for (int i = 0; i < vec.size(); ++i) {
            for (int j = i+1; j < vec.size(); ++j) {
                res.push_back(abs(vec[i] - vec[j]));
            }
        }
        sort(res.begin(), res.end());
        return res[0];
    }

    /*  VERY IMPORTANT...
        * 101. Symmetric Tree (Leetcode).
        * Link: https://leetcode.com/problems/symmetric-tree/description/
    */
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isMirror(root->left, root->right);
    }

    /*
        * 100. Same Tree (Leetcode).
        * Link: https://leetcode.com/problems/same-tree/description/
    */
    bool isSameTree(TreeNode* first, TreeNode* second) {
        if (!first && !second) return true;
        else if (!first || !second || first->val != second->val) return false;
        return isSame(first->left, second->left) && isSame(first->right, second->right);
    }
};

#endif //BST_PROBLEM_SOLVING_H
