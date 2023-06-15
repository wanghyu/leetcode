/**
 * @file   leetcode-base.h
 * @author 王怀宇
 * @date   2023/6/15
 * @desc 
**/

#ifndef LEETCODE_LEETCODE_BASE_H
#define LEETCODE_LEETCODE_BASE_H

#include<bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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

#endif //LEETCODE_LEETCODE_BASE_H