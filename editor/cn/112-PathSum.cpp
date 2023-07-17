//Given the root of a binary tree and an integer targetSum, return true if the 
//tree has a root-to-leaf path such that adding up all the values along the path 
//equals targetSum. 
//
// A leaf is a node with no children. 
//
// 
// Example 1: 
// 
// 
//Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
//Output: true
//Explanation: The root-to-leaf path with the target sum is shown.
// 
//
// Example 2: 
// 
// 
//Input: root = [1,2,3], targetSum = 5
//Output: false
//Explanation: There two root-to-leaf paths in the tree:
//(1 --> 2): The sum is 3.
//(1 --> 3): The sum is 4.
//There is no root-to-leaf path with sum = 5.
// 
//
// Example 3: 
//
// 
//Input: root = [], targetSum = 0
//Output: false
//Explanation: Since the tree is empty, there are no root-to-leaf paths.
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the tree is in the range [0, 5000]. 
// -1000 <= Node.val <= 1000 
// -1000 <= targetSum <= 1000 
// 
//
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 1203 👎 0


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
    bool hasPathSum(TreeNode* root, int targetSum) {
        stack<TreeNode*> sk;
        stack<int> sumSk;

        if(root) {
            sk.push(root);
            sumSk.push(root->val);
        }

        while(!sk.empty()) {
            auto node = sk.top(); sk.pop();
            int sum = sumSk.top(); sumSk.pop();

            if(sum == targetSum && node->left == nullptr && node->right == nullptr) {
                return true;
            }

            if(node->left) {
                sk.push(node->left);
                sumSk.push(sum + node->left->val);
            }

            if(node->right) {
                sk.push(node->right);
                sumSk.push(sum + node->right->val);
            }
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    
    return 0;
}