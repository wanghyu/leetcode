//Given the root of a binary tree, check whether it is a mirror of itself (i.e.,
// symmetric around its center). 
//
// 
// Example 1: 
// 
// 
//Input: root = [1,2,2,3,4,4,3]
//Output: true
// 
//
// Example 2: 
// 
// 
//Input: root = [1,2,2,null,3,null,3]
//Output: false
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the tree is in the range [1, 1000]. 
// -100 <= Node.val <= 100 
// 
//
// 
//Follow up: Could you solve it both recursively and iteratively?
//
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 2466 👎 0


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
    bool isVecSymm(vector<int>& nums) {
        if(nums.size() != 1 && nums.size() % 2) return false;

        int i,j;
        for(i = 0, j = nums.size()-1; i<j; i++,j--) {
            if(nums[i] != nums[j]) {
                return false;
            }
        }
        return true;
    }
public:
    /*
     * 层序遍历
     */
    bool isSymmetric2(TreeNode* root) {
        queue<TreeNode*> que;
        if(root) que.push(root);
        while(!que.empty()) {
            int size = que.size();
            vector<int> tmp;
            for(int i = 0; i < size; i++) {
                auto node = que.front();
                que.pop();

                if(node)
                    tmp.push_back(node->val);
                else
                    tmp.push_back(INT_MAX);
                if(node) {
                    que.push(node->left);
                    que.push(node->right);
                }
            }

            if(!isVecSymm(tmp)) return false;
        }
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root->left);
        que.push(root->right);
        while(!que.empty()) {
            auto left = que.front();
            que.pop();
            auto right = que.front();
            que.pop();
            //左右子树都是空 对称
            if(!left && !right) {
                continue;
            }

            if(!left || !right || left->val != right->val)
                return false;

            que.push(left->left);
            que.push(right->right);
            que.push(left->right);
            que.push(right->left);
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    
    return 0;
}