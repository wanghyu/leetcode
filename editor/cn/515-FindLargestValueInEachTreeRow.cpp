//Given the root of a binary tree, return an array of the largest value in each 
//row of the tree (0-indexed). 
//
// 
// Example 1: 
// 
// 
//Input: root = [1,3,2,5,3,null,9]
//Output: [1,3,9]
// 
//
// Example 2: 
//
// 
//Input: root = [1,2,3]
//Output: [1,3]
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the tree will be in the range [0, 10⁴]. 
// -2³¹ <= Node.val <= 2³¹ - 1 
// 
//
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 323 👎 0


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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> que;
        if(root) que.push(root);

        vector<int> res;
        while(!que.empty()) {
            int size = que.size();
            int m = INT32_MIN;
            for(int i = 0; i < size; i++) {
                auto node = que.front();
                que.pop();
                m = max(node->val, m);

                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            res.push_back(m);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    
    return 0;
}