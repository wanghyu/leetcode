//Given the root of a binary tree, return the preorder traversal of its nodes' 
//values. 
//
// 
// Example 1: 
// 
// 
//Input: root = [1,null,2,3]
//Output: [1,2,3]
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
// Follow up: Recursive solution is trivial, could you do it iteratively? 
//
// Related Topics 栈 树 深度优先搜索 二叉树 👍 1083 👎 0


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
        res.push_back(root->val);
        traversal(root->left, res);
        traversal(root->right, res);
    }
public:
    //递归
    vector<int> preorderTraversal2(TreeNode* root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }

    //迭代
    vector<int> preorderTraversal3(TreeNode* root) {
        vector<int> res;
        if(!root) return res;

        stack<TreeNode*> sk;
        sk.push(root);
        while(!sk.empty()) {
            auto node = sk.top();
            sk.pop();
            res.push_back(node->val);
            if(node->right) sk.push(node->right);
            if(node->left) sk.push(node->left);
        }
        return res;
    }

    //迭代
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;

        stack<TreeNode*> sk;
        sk.push(root);
        while(!sk.empty()){
            auto node = sk.top();
            if(node) {
                sk.pop();
                if(node->right) sk.push(node->right); //右
                if(node->left) sk.push(node->left); //左

                sk.push(node);  //中
                sk.push(nullptr);
            } else {
                sk.pop();
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