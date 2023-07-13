//Given an integer n, return the least number of perfect square numbers that 
//sum to n. 
//
// A perfect square is an integer that is the square of an integer; in other 
//words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 
//are perfect squares while 3 and 11 are not. 
//
// 
// Example 1: 
//
// 
//Input: n = 12
//Output: 3
//Explanation: 12 = 4 + 4 + 4.
// 
//
// Example 2: 
//
// 
//Input: n = 13
//Output: 2
//Explanation: 13 = 4 + 9.
// 
//
// 
// Constraints: 
//
// 
// 1 <= n <= 10⁴ 
// 
//
// Related Topics 广度优先搜索 数学 动态规划 👍 1744 👎 0


#include "leetcode-base.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    /*
     * 完全背包
     * dp[i] 整数i最少有dp[i]个square number
     * if n
     * dp[i] = min(dp[j], dp[j-i*i]+1)  if n is square number
     */
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;

        for(int i = 1; i*i <= n; i++) { //遍历物品
            for(int j = i*i; j <= n; j++) { //遍历背包
                dp[j] = min(dp[j], dp[j-i*i]+1);
            }
        }
        return dp[n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;

    cout << (int)sqrt(13) << endl;  //13-9 = 4
    return 0;
}