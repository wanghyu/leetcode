//You are given an integer array coins representing coins of different 
//denominations and an integer amount representing a total amount of money. 
//
// Return the number of combinations that make up that amount. If that amount 
//of money cannot be made up by any combination of the coins, return 0. 
//
// You may assume that you have an infinite number of each kind of coin. 
//
// The answer is guaranteed to fit into a signed 32-bit integer. 
//
// 
// Example 1: 
//
// 
//Input: amount = 5, coins = [1,2,5]
//Output: 4
//Explanation: there are four ways to make up the amount:
//5=5
//5=2+2+1
//5=2+1+1+1
//5=1+1+1+1+1
// 
//
// Example 2: 
//
// 
//Input: amount = 3, coins = [2]
//Output: 0
//Explanation: the amount of 3 cannot be made up just with coins of 2.
// 
//
// Example 3: 
//
// 
//Input: amount = 10, coins = [10]
//Output: 1
// 
//
// 
// Constraints: 
//
// 
// 1 <= coins.length <= 300 
// 1 <= coins[i] <= 5000 
// All the values of coins are unique. 
// 0 <= amount <= 5000 
// 
//
// Related Topics 数组 动态规划 👍 1109 👎 0


#include "leetcode-base.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //完全背包
    /*
     * dp[j]  凑成总金额为j的组合数 为dp[j]
     * dp[j] = dp[j-coins[0]]  + dp[j-coins[1] + ... + dp[j-coins[i]]
     */
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1; //只能为1

        //只能先遍历物品
        for(int i = 0; i < coins.size(); i++) { //遍历物品
            for(int j = coins[i]; j <= amount; j++) {
                dp[j] += dp[j-coins[i]];
            }
        }
        //printVec(dp);
        return dp[amount];
    }

    //这是排列数 不是组合数了
    int change2(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1; //只能为1

        for(int j = 0; j <= amount; j++) {
            for(int i = 0; i < coins.size(); i++) {
                if(j >= coins[i])
                    dp[j] += dp[j - coins[i]];
            }
        }

        printVec(dp);
        return dp[amount];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    vector<int> coins{1,2,5};
    cout << s.change(5, coins) << endl;
    return 0;
}