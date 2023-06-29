//The Fibonacci numbers, commonly denoted F(n) form a sequence, called the 
//Fibonacci sequence, such that each number is the sum of the two preceding ones, 
//starting from 0 and 1. That is, 
//
// 
//F(0) = 0, F(1) = 1
//F(n) = F(n - 1) + F(n - 2), for n > 1.
// 
//
// Given n, calculate F(n). 
//
// 
// Example 1: 
//
// 
//Input: n = 2
//Output: 1
//Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
// 
//
// Example 2: 
//
// 
//Input: n = 3
//Output: 2
//Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
// 
//
// Example 3: 
//
// 
//Input: n = 4
//Output: 3
//Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
// 
//
// 
// Constraints: 
//
// 
// 0 <= n <= 30 
// 
//
// Related Topics 递归 记忆化搜索 数学 动态规划 👍 656 👎 0


#include "leetcode-base.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    /*
     * 1. 确定dp数组 及其下标的含义
     * 2. 确定递推公式
     * 3. dp数组如何初始化
     * 4. 确定递归顺序
     * 5. 举例推导dp数组
     */
    int fib(int n) {
        if(n <= 1) return n;
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i =2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    
    return 0;
}