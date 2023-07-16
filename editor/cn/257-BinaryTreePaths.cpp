//Given the root of a binary tree, return all root-to-leaf paths in any order. 
//
// A leaf is a node with no children. 
//
// 
// Example 1: 
// 
// 
//Input: root = [1,2,3,null,5]
//Output: ["1->2->5","1->3"]
// 
//
// Example 2: 
//
// 
//Input: root = [1]
//Output: ["1"]
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the tree is in the range [1, 100]. 
// -100 <= Node.val <= 100 
// 
//
// Related Topics 树 深度优先搜索 字符串 回溯 二叉树 👍 979 👎 0


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
    //前序遍历 递归 递归中伴随着回溯
    void traversal(TreeNode* cur, vector<int>& path, vector<string>& res) {
        path.push_back(cur->val);

        string sPath;
        if(!cur->left && !cur->right) {
            for(int i = 0; i < path.size() - 1; i++) {
                sPath += to_string(path[i]);
                sPath += "->";
            }
            sPath += to_string(path[path.size()-1]);
            res.push_back(sPath);
        }

        if(cur->left) {
            traversal(cur->left, path, res);
            path.pop_back();
        }

        if(cur->right) {
            traversal(cur->right, path, res);
            path.pop_back();
        }

    }
    vector<string> binaryTreePaths2(TreeNode* root) {
        vector<string> res;
        vector<int> path;
        traversal(root, path, res);
        return res;
    }

    //迭代
    vector<string> binaryTreePaths(TreeNode* root) {
        stack<TreeNode*> sk;
        stack<string> path;
        vector<string> res;

        if(root) {
            sk.push(root);
            path.push(to_string(root->val));
        }

        while(!sk.empty()) {
            auto node = sk.top(); sk.pop();
            string pa = path.top(); path.pop();
            if(!node->left && !node->right) {
                res.push_back(pa);
            }

            if(node->right) {
                sk.push(node->right);
                path.push(pa + "->" + to_string(node->right->val));
            }

            if(node->left) {
                sk.push(node->left);
                path.push(pa + "->" + to_string(node->left->val));
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