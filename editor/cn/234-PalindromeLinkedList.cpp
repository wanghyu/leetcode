//Given the head of a singly linked list, return true if it is a palindrome or 
//false otherwise. 
//
// 
// Example 1: 
// 
// 
//Input: head = [1,2,2,1]
//Output: true
// 
//
// Example 2: 
// 
// 
//Input: head = [1,2]
//Output: false
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the list is in the range [1, 10⁵]. 
// 0 <= Node.val <= 9 
// 
//
// 
//Follow up: Could you do it in 
//O(n) time and 
//O(1) space?
//
// Related Topics 栈 递归 链表 双指针 👍 1719 👎 0


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
    bool isPalindrome2(ListNode* head) {
        stack<int> sk;
        ListNode* cur = head;
        while(cur) {
            sk.push(cur->val);
            cur = cur->next;
        }

        cur = head;
        while(cur) {
            if(cur->val != sk.top()) {
                return false;
            } else {
                sk.pop();
                cur = cur->next;
            }
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    
    return 0;
}