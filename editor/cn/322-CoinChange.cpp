//You are given an integer array coins representing coins of different 
//denominations and an integer amount representing a total amount of money. 
//
// Return the fewest number of coins that you need to make up that amount. If 
//that amount of money cannot be made up by any combination of the coins, return -1.
// 
//
// You may assume that you have an infinite number of each kind of coin. 
//
// 
// Example 1: 
//
// 
//Input: coins = [1,2,5], amount = 11
//Output: 3
//Explanation: 11 = 5 + 5 + 1
// 
//
// Example 2: 
//
// 
//Input: coins = [2], amount = 3
//Output: -1
// 
//
// Example 3: 
//
// 
//Input: coins = [1], amount = 0
//Output: 0
// 
//
// 
// Constraints: 
//
// 
// 1 <= coins.length <= 12 
// 1 <= coins[i] <= 2³¹ - 1 
// 0 <= amount <= 10⁴ 
// 
//
// Related Topics 广度优先搜索 数组 动态规划 👍 2476 👎 0


#include "leetcode-base.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //完全背包 组合
    /*
     * dp[j] amount 为j时最少数量的币种是dp[j]
     * dp[j] = min(dp[j], dp[j-nums[i]] + 1)
     *
     */
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;

        //内外循环无所谓，既不是组合也不是排列
        for(int i = 0; i < coins.size(); i++) {
            for(int j = 0; j <= amount; j++) {
                if(j >= coins[i] && dp[j-coins[i]] != INT_MAX) {
                    dp[j] = min(dp[j], dp[j-coins[i]] + 1);
                }
            }
        }
        //printVec(dp);
        if(dp[amount] == INT_MAX) return -1;
        return dp[amount];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    vector<int> coins{1,2,5};
    cout << s.coinChange(coins, 11) << endl;
    return 0;
}