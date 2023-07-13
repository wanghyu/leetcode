//The thief has found himself a new place for his thievery again. There is only 
//one entrance to this area, called root. 
//
// Besides the root, each house has one and only one parent house. After a tour,
// the smart thief realized that all houses in this place form a binary tree. It 
//will automatically contact the police if two directly-linked houses were broken 
//into on the same night. 
//
// Given the root of the binary tree, return the maximum amount of money the 
//thief can rob without alerting the police. 
//
// 
// Example 1: 
// 
// 
//Input: root = [3,2,3,null,3,null,1]
//Output: 7
//Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
// 
//
// Example 2: 
// 
// 
//Input: root = [3,4,5,1,3,null,1]
//Output: 9
//Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the tree is in the range [1, 10⁴]. 
// 0 <= Node.val <= 10⁴ 
// 
//
// Related Topics 树 深度优先搜索 动态规划 二叉树 👍 1711 👎 0


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
    /*
     * 返回值 dp[0]表示不偷  dp[1]表示偷
     * 是一种后续遍历
     */
    vector<int> robTree(TreeNode* cur) {
        if(cur == nullptr) return {0, 0};

        vector<int> left = robTree(cur->left);
        vector<int> right = robTree(cur->right);

        //偷当前节点  左右孩子都不能偷了
        int value1 = cur->val + left[0] + right[0];
        //不偷当前节点
        int value2 = max(left[0], left[1]) + max(right[0], right[1]);
        return {value2, value1};
    }

    //动态规划
    int rob2(TreeNode* root) {
        auto res = robTree(root);
        return max(res[0], res[1]);
    }

    //暴力  超时了
    int rob(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return root->val;

        //偷父节点
        int val1 = root->val;
        if(root->left) val1 += rob(root->left->left) + rob(root->left->right);
        if(root->right) val1 += rob(root->right->left) + rob(root->right->right);

        //不偷父节点
        int val2 = rob(root->left) + rob(root->right);
        return max(val1, val2);
    }

};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    
    return 0;
}