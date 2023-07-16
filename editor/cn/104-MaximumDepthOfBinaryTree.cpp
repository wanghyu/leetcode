//Given the root of a binary tree, return its maximum depth. 
//
// A binary tree's maximum depth is the number of nodes along the longest path 
//from the root node down to the farthest leaf node. 
//
// 
// Example 1: 
// 
// 
//Input: root = [3,9,20,null,null,15,7]
//Output: 3
// 
//
// Example 2: 
//
// 
//Input: root = [1,null,2]
//Output: 2
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the tree is in the range [0, 10⁴]. 
// -100 <= Node.val <= 100 
// 
//
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 1635 👎 0


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
    //迭代  层序遍历
    int maxDepth2(TreeNode* root) {
        queue<TreeNode*> que;
        if(root) que.push(root);

        int dep = 0;
        while(!que.empty()) {
            int size = que.size();
            for(int i = 0; i < size; i++) {
                auto node = que.front();
                que.pop();

                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            dep++;
        }
        return dep;
    }

    //递归
    int maxDepth3(TreeNode* root) {
        if(!root) return 0;
        return max(1 + maxDepth(root->left), 1 + maxDepth(root->right));
    }

    //前序 深度回溯
    int maxDepth(TreeNode* root) {

    }

};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    
    return 0;
}