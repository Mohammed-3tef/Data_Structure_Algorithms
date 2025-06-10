#ifndef SINGLE_LINKED_LIST_PROBLEM_SOLVING_H
#define SINGLE_LINKED_LIST_PROBLEM_SOLVING_H

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution {
private:
    int binaryToDecimal(const string& n){
        string num = n;
        int dec_value = 0;

        int base = 1, len = num.size();
        for (int i = len - 1; i >= 0; i--) {
            if (num[i] == '1') dec_value += base;
            base = base * 2;
        }

        return dec_value;
    }

    int findSize(ListNode *head) const {
        ListNode *current = head;
        int size = 0;
        while (current) {
            size++;
            current = current->next;
        }
        return size;
    }

    int findSize(Node *head) const {
        Node *current = head;
        int size = 0;
        while (current) {
            size++;
            current = current->next;
        }
        return size;
    }

public:
    /*
        * 234. Palindrome Linked List (Leetcode).
        * Link: https://leetcode.com/problems/palindrome-linked-list/description/
    */
    bool isPalindrome(ListNode* head) {
        string res;
        ListNode * current = head;
        if (!head->next) return true;

        while (current){
            res += to_string(current->val);
            current = current->next;
        }

        for (int i = 0; i < res.size()/2; ++i) {
            if (res[i] != res[res.size() -1-i]) return false;
        }
        return true;
    }

    /*
        * 206. Reverse Linked List (Leetcode).
        * Link: https://leetcode.com/problems/reverse-linked-list/description/
    */
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;

        vector<int> temp;
        ListNode *current = head;
        while (current){
            temp.push_back(current->val);
            current = current->next;
        }

        ListNode *res = new ListNode(temp[temp.size() -1]);
        ListNode *dummy = res;
        for (int i = temp.size() -2; i >= 0; --i) {
            dummy->next = new ListNode(temp[i]);
            dummy = dummy->next;
        }
        return res;
    }

    /*
        * 92. Reverse Linked List II (Leetcode).
        * Link: https://leetcode.com/problems/reverse-linked-list-ii/description/
    */
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head) return nullptr;

        vector<int> temp;
        ListNode *current = head;
        while (current){
            temp.push_back(current->val);
            current = current->next;
        }

        reverse(temp.begin() + left - 1, temp.begin() + right);

        ListNode *res = new ListNode(temp[0]);
        ListNode *dummy = res;
        for (int i = 1; i < temp.size(); ++i) {
            dummy->next = new ListNode(temp[i]);
            dummy = dummy->next;
        }
        return res;
    }

    /*
        * 21. Merge Two Sorted Lists (Leetcode).
        * Link: https://leetcode.com/problems/merge-two-sorted-lists/description/
    */
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 && !list2) return nullptr;

        vector<int> temp;
        ListNode *current1 = list1;
        ListNode *current2 = list2;
        while (current1){
            temp.push_back(current1->val);
            current1 = current1->next;
        }
        while (current2){
            temp.push_back(current2->val);
            current2 = current2->next;
        }

        sort(temp.begin(), temp.end());

        ListNode *res = new ListNode(temp[0]);
        ListNode *dummy = res;
        for (int i = 1; i < temp.size(); ++i) {
            dummy->next = new ListNode(temp[i]);
            dummy = dummy->next;
        }
        return res;
    }

    /*
        * 876. Middle of the Linked List (Leetcode).
        * Link: https://leetcode.com/problems/merge-two-sorted-lists/description/
    */
    ListNode* middleNode(ListNode* head) {
        if (!head) return nullptr;

        vector<ListNode*> temp;
        ListNode *current = head;
        while (current){
            temp.push_back(current);
            current = current->next;
        }

        int middle = temp.size() /2;
        ListNode *res = head;
        while(middle--)
            res = res->next;
        return res;
    }

    /*
        * 1290. Convert Binary Number in a Linked List to Integer (Leetcode).
        * Link: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/description/
    */
    int getDecimalValue(ListNode* head) {
        string res;
        ListNode * current = head;
        while (current){
            res += to_string(current->val);
            current = current->next;
        }

        return binaryToDecimal(res);
    }

    /*
        * 19. Remove Nth Node From End of List (Leetcode).
        * Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
    */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *current = head;
        int size = findSize(current);

        ListNode *res = nullptr, *dummy = nullptr;
        int index = 0;
        int skipIndex = size - n;

        while (current) {
            if (index != skipIndex) {
                if (!res) {
                    res = new ListNode(current->val);
                    dummy = res;
                } else {
                    dummy->next = new ListNode(current->val);
                    dummy = dummy->next;
                }
            }
            current = current->next;
            index++;
        }

        return res;
    }

    /*
        * 203. Remove Linked List Elements (Leetcode).
        * Link: https://leetcode.com/problems/remove-linked-list-elements/description/
    */
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return nullptr;

        ListNode * current = head;
        ListNode *res = nullptr, *dummy = nullptr;
        while (current) {
            if (current->val != val) {
                if (!res) {
                    res = new ListNode(current->val);
                    dummy = res;
                } else {
                    dummy->next = new ListNode(current->val);
                    dummy = dummy->next;
                }
            }
            current = current->next;
        }

        return res;
    }

    /*
        * 2095. Delete the Middle Node of a Linked List (Leetcode).
        * Link: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/
    */
    ListNode* deleteMiddle(ListNode* head) {
        if (!head) return nullptr;

        ListNode *current = head;
        int size = findSize(current);

        int mid = size /2, temp = 0;
        ListNode *res = nullptr, *dummy = nullptr;
        while (current) {
            if (temp != mid) {
                if (!res) {
                    res = new ListNode(current->val);
                    dummy = res;
                } else {
                    dummy->next = new ListNode(current->val);
                    dummy = dummy->next;
                }
            }
            current = current->next;
            temp++;
        }

        return res;
    }

    /*
        * 83. Remove Duplicates from Sorted List (Leetcode).
        * Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
    */
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;
        ListNode *res = new ListNode(head->val);
        ListNode *dummy = res;

        while (head){
            if (dummy->val != head->val) {
                dummy->next = new ListNode(head->val);
                dummy = dummy->next;
            }
            head = head->next;
        }
        return res;
    }

    /*
        * 148. Sort List (Leetcode).
        * Link: https://leetcode.com/problems/sort-list/description/
    */
    ListNode* sortList(ListNode* head) {
        if (!head) return nullptr;

        vector<int> temp;
        ListNode *current = head;
        while (current){
            temp.push_back(current->val);
            current = current->next;
        }

        sort(temp.begin(), temp.end());
        ListNode *res = new ListNode(temp[0]);
        ListNode *dummy = res;
        for (int i = 1; i < temp.size(); ++i) {
            dummy->next = new ListNode(temp[i]);
            dummy = dummy->next;
        }
        return res;
    }

    /*
        * 147. Insertion Sort List (Leetcode).
        * Link: https://leetcode.com/problems/insertion-sort-list/description/
    */
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return nullptr;

        vector<int> temp;
        ListNode *current = head;
        while (current){
            temp.push_back(current->val);
            current = current->next;
        }

        sort(temp.begin(), temp.end());
        ListNode *res = new ListNode(temp[0]);
        ListNode *dummy = res;
        for (int i = 1; i < temp.size(); ++i) {
            dummy->next = new ListNode(temp[i]);
            dummy = dummy->next;
        }
        return res;
    }

    /*
        * Node at a given index in linked list (Geeks for Geeks).
        * Link: https://www.geeksforgeeks.org/problems/node-at-a-given-index-in-linked-list/1?page=1&category=Linked%20List&sprint=ca8ae412173dbd8346c26a0295d098fd&sortBy=submissions
    */
    int GetNth(Node *head, int index) {
        if (!head) return -1;

        Node *current = head;
        int size = findSize(current);
        if (index <= 0 || index > size) return -1;

        int temp = 1;
        while (current){
            if (temp == index) return current->data;
            current = current->next;
            temp++;
        }
        return -1;
    }

    /*
        * Find n/k th node in Linked list (Geeks for Geeks).
        * Link: https://www.geeksforgeeks.org/problems/find-nk-th-node-in-linked-list/1?page=1&category=Linked%20List&sprint=ca8ae412173dbd8346c26a0295d098fd&sortBy=submissions
    */
    int fractional_node(struct Node *head, int k) {
        Node *current = head;
        int size = findSize(current);

        if (size == 1) return current->data;

        int temp = 1;
        while (current){
            if (temp == ceil(double(size)/k)) return current->data;
            current = current->next;
            temp++;
        }
        return -1;
    }

    /*
        * 61. Rotate List (Leetcode).
        * Link: https://leetcode.com/problems/rotate-list/description/
    */
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return nullptr;

        vector<int> temp;
        ListNode *current = head;
        while (current){
            temp.push_back(current->val);
            current = current->next;
        }

        while (k--){
            temp.insert(temp.begin(), *temp.rbegin());
            temp.erase(temp.begin() + temp.size());
            if (k %temp.size() == 0) break;
        }

        ListNode *res = new ListNode(temp[0]);
        ListNode *dummy = res;
        for (int i = 1; i < temp.size(); ++i) {
            dummy->next = new ListNode(temp[i]);
            dummy = dummy->next;
        }
        return res;
    }
};

#endif //SINGLE_LINKED_LIST_PROBLEM_SOLVING_H