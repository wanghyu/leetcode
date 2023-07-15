//Given the root of a binary tree, invert the tree, and return its root. 
//
// 
// Example 1: 
// 
// 
//Input: root = [4,2,7,1,3,6,9]
//Output: [4,7,2,9,6,3,1]
// 
//
// Example 2: 
// 
// 
//Input: root = [2,1,3]
//Output: [2,3,1]
// 
//
// Example 3: 
//
// 
//Input: root = []
//Output: []
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the tree is in the range [0, 100]. 
// -100 <= Node.val <= 100 
// 
//
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 1632 👎 0


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
    //前序遍历 dfs
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> sk;
        if(root) sk.push(root);
        while(!sk.empty()) {
            auto node = sk.top();
            if(node) {
                sk.pop();
                if(node->right) sk.push(node->right);
                if(node->left) sk.push(node->left);

                sk.push(node);
                sk.push(nullptr);
            } else {
                sk.pop();
                node = sk.top();
                sk.pop();
                swap(node->left, node->right);
            }
        }
        return root;
    }

    TreeNode* invertTree2(TreeNode* root) {
        /*
         * 层序遍历，交换左右孩子
         */

        queue<TreeNode*> que;
        if(root) que.push(root);
        while(!que.empty()) {
            int size = que.size();
            for(int i = 0; i < size; i++) {
                auto node = que.front();
                que.pop();

                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);

                swap(node->left, node->right);
            }
        }
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    
    return 0;
}