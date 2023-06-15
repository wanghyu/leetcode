//You are given two non-empty linked lists representing two non-negative 
//integers. The digits are stored in reverse order, and each of their nodes contains a 
//single digit. Add the two numbers and return the sum as a linked list. 
//
// You may assume the two numbers do not contain any leading zero, except the 
//number 0 itself. 
//
// 
// Example 1: 
// 
// 
//Input: l1 = [2,4,3], l2 = [5,6,4]
//Output: [7,0,8]
//Explanation: 342 + 465 = 807.
// 
//
// Example 2: 
//
// 
//Input: l1 = [0], l2 = [0]
//Output: [0]
// 
//
// Example 3: 
//
// 
//Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
//Output: [8,9,9,9,0,0,0,1]
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in each linked list is in the range [1, 100]. 
// 0 <= Node.val <= 9 
// It is guaranteed that the list represents a number that does not have 
//leading zeros. 
// 
//
// Related Topics 递归 链表 数学 👍 9665 👎 0


#include "leetcode-base.h"

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int k = 0; //进位
        ListNode* newHead = new ListNode;
        ListNode*cur = newHead;
        int value;
        while(l1 && l2) {
            value = l1->val + l2->val + k;
            cur->next = new ListNode(value % 10);
            cur = cur->next;

            k = value / 10;

            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1) {
            value = l1->val + k;
            cur->next = new ListNode(value % 10);
            cur = cur->next;

            k = value / 10;

            l1 = l1->next;
        }

        while(l2) {
            value = l2->val + k;
            cur->next = new ListNode(value % 10);
            cur = cur->next;
            k = value / 10;

            l2 = l2->next;
        }

        if(k != 0) {
            cur->next = new ListNode(k);
        }

        return newHead->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    ListNode l3(3, nullptr);
    ListNode l2(4, &l3);
    ListNode l1(2, &l2);

    ListNode k3(4, nullptr);
    ListNode k2(6, &k3);
    ListNode k1(5, &k2);

    auto head = s.addTwoNumbers(&l1, &k1);
    printList(head);
    
    return 0;
}