//Given an integer n, return the number of structurally unique BST's (binary 
//search trees) which has exactly n nodes of unique values from 1 to n. 
//
// 
// Example 1: 
// 
// 
//Input: n = 3
//Output: 5
// 
//
// Example 2: 
//
// 
//Input: n = 1
//Output: 1
// 
//
// 
// Constraints: 
//
// 
// 1 <= n <= 19 
// 
//
// Related Topics 树 二叉搜索树 数学 动态规划 二叉树 👍 2282 👎 0


#include "leetcode-base.h"

/*
 *  dp[i] 数字i有dp[i]种
 *
 *  dp[i] = dp[0]*dp[i-1] + dp[1] * dp[i-1-1] + dp[2]*dp[i-2-1] + ...
 *  dp[i] += dp[j-1]*dp[i-j]
 *
 *  dp[0]
 *  dp[1] = 1
 *  dp[2] = 2;
 *  dp[3] = 5;
 */

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1); //数字i有dp[i]种
        dp[0] = 1;
        for(int i =1; i <= n; i++) {
            for(int j = 1; j <= i; j++) {
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        return dp[n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    cout << s.numTrees(4) << endl;
    return 0;
}