//Given the roots of two binary trees root and subRoot, return true if there is 
//a subtree of root with the same structure and node values of subRoot and false 
//otherwise. 
//
// A subtree of a binary tree tree is a tree that consists of a node in tree 
//and all of this node's descendants. The tree tree could also be considered as a 
//subtree of itself. 
//
// 
// Example 1: 
// 
// 
//Input: root = [3,4,5,1,2], subRoot = [4,1,2]
//Output: true
// 
//
// Example 2: 
// 
// 
//Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
//Output: false
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the root tree is in the range [1, 2000]. 
// The number of nodes in the subRoot tree is in the range [1, 1000]. 
// -10⁴ <= root.val <= 10⁴ 
// -10⁴ <= subRoot.val <= 10⁴ 
// 
//
// Related Topics 树 深度优先搜索 二叉树 字符串匹配 哈希函数 👍 932 👎 0


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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;

        queue<TreeNode*> que;
        que.push(p);
        que.push(q);
        while(!que.empty()) {
            auto n1 = que.front();
            que.pop();
            auto n2 = que.front();
            que.pop();

            if(!n1 && !n2) continue;

            if(!n1 || !n2 || n1->val != n2->val) {
                return false;
            }

            que.push(n1->left);
            que.push(n2->left);
            que.push(n1->right);
            que.push(n2->right);
        }
        return true;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) return true;
        if(!root) return false;
        return isSameTree(root, subRoot) ||
                isSubtree(root->left, subRoot) ||
                isSubtree(root->right, subRoot);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    
    return 0;
}