/**
 * @file   leetcode-base.h
 * @author 王怀宇
 * @date   2023/6/15
 * @desc 
**/

#ifndef LEETCODE_LEETCODE_BASE_H
#define LEETCODE_LEETCODE_BASE_H

#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


void printList(ListNode* head) {
    ListNode* tmpHead = head;
    cout << "list:";
    while(tmpHead) {
        ::printf("%d ", tmpHead->val);
        tmpHead = tmpHead->next;
    }
    printf("\n");
}

template<typename T>
void printVec(vector<T> vec) {
    cout << "vector:";
    for(auto t : vec) {
        cout << t << " ";
    }
    cout << endl;
}

template<typename T>
void printVecVec(vector<vector<T>> vec) {
    for(auto t : vec) {
        printVec(t);
    }
    cout << endl;
}

template<typename T>
void printStack(const stack<T> sk) {
    auto tmp = sk;
    cout << "stack:";
    while(!tmp.empty()) {
        cout << tmp.top()<< " ";
        tmp.pop();
    }
    cout << endl;
}



/*
    ListNode l5(5, nullptr);
    ListNode l4(4, &l5);
    ListNode l3(3, &l4);
    ListNode l2(2, &l3);
    ListNode l1(1, &l2);
 */

#endif //LEETCODE_LEETCODE_BASE_H
