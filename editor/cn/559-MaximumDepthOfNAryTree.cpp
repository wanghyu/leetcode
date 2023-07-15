//Given a n-ary tree, find its maximum depth. 
//
// The maximum depth is the number of nodes along the longest path from the 
//root node down to the farthest leaf node. 
//
// Nary-Tree input serialization is represented in their level order traversal, 
//each group of children is separated by the null value (See examples). 
//
// 
// Example 1: 
//
// 
//
// 
//Input: root = [1,null,3,2,4,null,5,6]
//Output: 3
// 
//
// Example 2: 
//
// 
//
// 
//Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,
//null,12,null,13,null,null,14]
//Output: 5
// 
//
// 
// Constraints: 
//
// 
// The total number of nodes is in the range [0, 10⁴]. 
// The depth of the n-ary tree is less than or equal to 1000. 
// 
//
// Related Topics 树 深度优先搜索 广度优先搜索 👍 351 👎 0


#include "leetcode-base.h"

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

//leetcode submit region begin(Prohibit modification and deletion)
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    //递归  超时了
    int maxDepth2(Node* root) {
        if(!root) return 0;
        int depth = 0;
        for(int i = 0; i < root->children.size(); i++) {
            depth = depth > maxDepth2(root->children[i]) ? depth : maxDepth2(root->children[i]);
        }
        return 1 + depth;
    }

    int maxDepth(Node* root) {
        if(!root) return 0;

        queue<Node*> que;
        que.push(root);

        int dep = 0;
        while(!que.empty()) {
            dep++;

            int size = que.size();
            for(int i = 0; i < size; i++) {
                auto node = que.front(); que.pop();
                for(auto ch : node->children) {
                    if(ch) que.push(ch);
                }
            }
        }
        return dep;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    
    return 0;
}