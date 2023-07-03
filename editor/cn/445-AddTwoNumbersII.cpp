//You are given two non-empty linked lists representing two non-negative 
//integers. The most significant digit comes first and each of their nodes contains a 
//single digit. Add the two numbers and return the sum as a linked list. 
//
// You may assume the two numbers do not contain any leading zero, except the 
//number 0 itself. 
//
// 
// Example 1: 
// 
// 
//Input: l1 = [7,2,4,3], l2 = [5,6,4]
//Output: [7,8,0,7]
// 
//
// Example 2: 
//
// 
//Input: l1 = [2,4,3], l2 = [5,6,4]
//Output: [8,0,7]
// 
//
// Example 3: 
//
// 
//Input: l1 = [0], l2 = [0]
//Output: [0]
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
// 
// Follow up: Could you solve it without reversing the input lists? 
//
// Related Topics 栈 链表 数学 👍 656 👎 0


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
        stack<int> sk1;
        stack<int> sk2;
        stack<int> res;

        while(l1) {
            sk1.push(l1->val);
            l1 = l1->next;
        }

        while(l2) {
            sk2.push(l2->val);
            l2 = l2->next;
        }

        int v = 0;
        while(!sk1.empty() && !sk2.empty()) {
            int v1 = sk1.top();
            sk1.pop();
            int v2 = sk2.top();
            sk2.pop();

            res.push((v+ v1 + v2) % 10);
            v = (v+ v1 + v2) / 10;
        }

        while(!sk1.empty()) {
            int v1 = sk1.top();
            sk1.pop();

            res.push((v + v1) % 10);
            v = (v + v1) / 10;
        }

        while(!sk2.empty()) {
            int v2 = sk2.top();
            sk2.pop();

            res.push((v + v2) % 10);
            v = (v + v2) / 10;
        }
        if(v != 0) {
            res.push(1);
        }

        ListNode* dummy = new ListNode;
        ListNode* cur = dummy;
        ListNode* tmp = nullptr;
        while(!res.empty()) {
            tmp = new ListNode(res.top());
            res.pop();
            cur->next = tmp;
            cur = tmp;
        }
        return dummy->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    
    return 0;
}