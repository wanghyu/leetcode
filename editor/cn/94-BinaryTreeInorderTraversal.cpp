//Given the root of a binary tree, return the inorder traversal of its nodes' 
//values. 
//
// 
// Example 1: 
// 
// 
//Input: root = [1,null,2,3]
//Output: [1,3,2]
// 
//
// Example 2: 
//
// 
//Input: root = []
//Output: []
// 
//
// Example 3: 
//
// 
//Input: root = [1]
//Output: [1]
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
// 
//Follow up: Recursive solution is trivial, could you do it iteratively?
//
// Related Topics 栈 树 深度优先搜索 二叉树 👍 1857 👎 0


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
private:
    void traversal(TreeNode* root, vector<int>& res) {
        if(!root) return;
        traversal(root->left, res);
        res.push_back(root->val);
        traversal(root->right, res);
    }
public:
    //递归
    vector<int> inorderTraversal2(TreeNode* root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }

    //迭代
    vector<int> inorderTraversal3(TreeNode* root) {
        vector<int> res;
        if(!root) return res;

        stack<TreeNode*> sk;
        auto cur = root;
        while(cur != nullptr || !sk.empty()) {
            if(cur != nullptr) {
                sk.push(cur);
                cur = cur->left;  //左
            } else {
                auto node = sk.top();
                sk.pop();
                res.push_back(node->val);  //中
                cur = node->right;  //右
            }
        }
        return res;
    }


    //迭代 统一发
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;

        stack<TreeNode*> sk;
        sk.push(root);
        while(!sk.empty()) {
            auto node = sk.top();
            if(node) {
                sk.pop();
                if(node->right) sk.push(node->right);

                sk.push(node);
                sk.push(nullptr);
                if(node->left) sk.push(node->left);
            } else {
                sk.pop(); //nullptr
                node = sk.top();
                sk.pop();
                res.push_back(node->val);
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