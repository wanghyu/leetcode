//Given the root of a binary tree, return the sum of all left leaves. 
//
// A leaf is a node with no children. A left leaf is a leaf that is the left 
//child of another node. 
//
// 
// Example 1: 
// 
// 
//Input: root = [3,9,20,null,null,15,7]
//Output: 24
//Explanation: There are two left leaves in the binary tree, with values 9 and 1
//5 respectively.
//
//
// Example 2: 
//
// 
//Input: root = [1]
//Output: 0
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the tree is in the range [1, 1000]. 
// -1000 <= Node.val <= 1000 
// 
//
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 622 👎 0


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
    //层次遍历
    int sumOfLeftLeaves2(TreeNode* root) {
        int sum = 0;
        queue<TreeNode*> que;
        if(root) que.push(root);
        while(!que.empty()) {
            int size = que.size();
            for(int i = 0; i < size; i++) {
                auto node = que.front(); que.pop();
                if(node->left && node->left->left == nullptr && node->left->right == nullptr ) {
                    sum += node->left->val;
                }

                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
        }
        return sum;
    }

    //递归 后序遍历
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;

        int leftSum = sumOfLeftLeaves(root->left);
        if(root->left && root->left->left == nullptr && root->left->right == nullptr) {
            leftSum = root->left->val;
        }

        int rightSum = sumOfLeftLeaves(root->right);

        return leftSum + rightSum;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    
    return 0;
}