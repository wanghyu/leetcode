//Given the roots of two binary trees p and q, write a function to check if 
//they are the same or not. 
//
// Two binary trees are considered the same if they are structurally identical, 
//and the nodes have the same value. 
//
// 
// Example 1: 
// 
// 
//Input: p = [1,2,3], q = [1,2,3]
//Output: true
// 
//
// Example 2: 
// 
// 
//Input: p = [1,2], q = [1,null,2]
//Output: false
// 
//
// Example 3: 
// 
// 
//Input: p = [1,2,1], q = [1,1,2]
//Output: false
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in both trees is in the range [0, 100]. 
// -10⁴ <= Node.val <= 10⁴ 
// 
//
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 1035 👎 0


#include "leetcode-base.h"

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //迭代
    bool isSameTree2(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;

        queue<TreeNode*> que;
        que.push(p);
        que.push(q);
        while(!que.empty()) {
            auto n1 = que.front();
            que.pop();

            auto n2 = que.front();
            que.pop();

            if(!n1 && !n2) continue;

            if(!n1 || !n2 || n1->val != n2->val) {
                return false;
            }

            que.push(n1->left);
            que.push(n2->left);
            que.push(n1->right);
            que.push(n2->right);
        }
        return true;
    }

    bool compare(TreeNode* p, TreeNode* q) {
        if(!p && q) return false;
        if(p && !q) return false;
        if(!p && !q) return true;
        if(p->val != q->val) return false;

        return compare(p->left, q->left) && compare(p->right, q->right);
    }

    //递归
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return compare(p, q);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    
    return 0;
}