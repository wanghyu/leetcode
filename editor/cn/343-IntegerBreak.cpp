//Given an integer n, break it into the sum of k positive integers, where k >= 2
//, and maximize the product of those integers. 
//
// Return the maximum product you can get. 
//
// 
// Example 1: 
//
// 
//Input: n = 2
//Output: 1
//Explanation: 2 = 1 + 1, 1 × 1 = 1.
// 
//
// Example 2: 
//
// 
//Input: n = 10
//Output: 36
//Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
// 
//
// 
// Constraints: 
//
// 
// 2 <= n <= 58 
// 
//
// Related Topics 数学 动态规划 👍 1218 👎 0


#include "leetcode-base.h"

/*
 * dp[i]  分拆数字i, 可以得到的最大乘积为dp[i]
 * dp[i] = max(dp[i], max( (i-j)*j, dp[i-j] * j))
 * dp[2] = 1;
 * dp[3] = 2;
 */

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1);
        dp[2] = 1;
        for(int i = 2; i <= n; i++) {
            for(int j = 1; j <= i; j++) {
                dp[i] = max(dp[i], max(j * (i-j), dp[i-j] * j));
            }
        }
        return dp[n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    cout << s.integerBreak(10) << endl;
    return 0;
}