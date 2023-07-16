//Given a binary tree, determine if it is height-balanced. 
//
// 
// Example 1: 
// 
// 
//Input: root = [3,9,20,null,null,15,7]
//Output: true
// 
//
// Example 2: 
// 
// 
//Input: root = [1,2,2,3,3,null,null,4,4]
//Output: false
// 
//
// Example 3: 
//
// 
//Input: root = []
//Output: true
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the tree is in the range [0, 5000]. 
// -10⁴ <= Node.val <= 10⁴ 
// 
//
// Related Topics 树 深度优先搜索 二叉树 👍 1354 👎 0


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
    //后续
    int getHeight(TreeNode* root) {
        if(!root) return 0;

        int left = getHeight(root->left);
        if(left == -1) return -1;
        int right = getHeight(root->right);
        if(right == -1) return -1;

        if(abs(left-right) > 1) return -1;

        return 1 + max(left, right);
    }
    //递归 高度要用后续遍历
    bool isBalanced2(TreeNode* root) {
        if(!root) return true;
        if(getHeight(root) == -1) return false;
        if(abs(getHeight(root->left) - getHeight(root->right) > 1)) return false;
        return true;
    }

    //迭代 后序遍历
    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        stack<TreeNode*> sk;
        sk.push(root);
        while(!sk.empty()) {
            auto node = sk.top(); sk.pop();
            if(abs(getDepth(node->left) - getDepth(node->right)) > 1)
                return false;

            if(node->right) sk.push(node->right);
            if(node->left) sk.push(node->left);
        }
        return true;
    }

    //求cur节点当前的高度  后续
    int getDepth(TreeNode* cur) {
        stack<TreeNode*> sk;
        if(cur) sk.push(cur);

        int depth = 0;
        int result = 0;

        while(!sk.empty()) {
            auto node = sk.top();
            if(node) {
                sk.push(nullptr);
                depth++;
                if(node->right) sk.push(node->right);
                if(node->left) sk.push(node->left);
            } else {
                sk.pop();
                sk.top(); sk.pop();
                depth--;
            }
            result = max(result, depth);
        }
        if(cur)
            cout << cur->val <<  " " << result << endl;
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    
    return 0;
}