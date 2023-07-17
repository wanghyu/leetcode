//Given the root of a binary tree and an integer targetSum, return all root-to-
//leaf paths where the sum of the node values in the path equals targetSum. Each 
//path should be returned as a list of the node values, not node references. 
//
// A root-to-leaf path is a path starting from the root and ending at any leaf 
//node. A leaf is a node with no children. 
//
// 
// Example 1: 
// 
// 
//Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
//Output: [[5,4,11,2],[5,8,4,5]]
//Explanation: There are two paths whose sum equals targetSum:
//5 + 4 + 11 + 2 = 22
//5 + 8 + 4 + 5 = 22
// 
//
// Example 2: 
// 
// 
//Input: root = [1,2,3], targetSum = 5
//Output: []
// 
//
// Example 3: 
//
// 
//Input: root = [1,2], targetSum = 0
//Output: []
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
// Related Topics 树 深度优先搜索 回溯 二叉树 👍 1002 👎 0


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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        stack<TreeNode*> sk;
        vector<vector<int>> paths;

        vector<vector<int>> res;

        if(root) {
            sk.push(root);
            paths.push_back({root->val});
        }

        while(!sk.empty()) {
            auto node = sk.top(); sk.pop();
            vector<int> path = paths.back(); paths.pop_back();

            if(accumulate(path.begin(), path.end(), 0) == targetSum
                && !node->left && !node->right) {
                res.push_back(path);
            }

            if(node->left) {
                sk.push(node->left);
                auto p = path;
                p.push_back(node->left->val);
                paths.push_back(p);
            }

            if(node->right) {
                sk.push(node->right);
                auto p = path;
                p.push_back(node->right->val);
                paths.push_back(p);
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    
    return 0;
}