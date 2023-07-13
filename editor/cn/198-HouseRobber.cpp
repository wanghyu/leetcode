//You are a professional robber planning to rob houses along a street. Each 
//house has a certain amount of money stashed, the only constraint stopping you from 
//robbing each of them is that adjacent houses have security systems connected and 
//it will automatically contact the police if two adjacent houses were broken 
//into on the same night. 
//
// Given an integer array nums representing the amount of money of each house, 
//return the maximum amount of money you can rob tonight without alerting the 
//police. 
//
// 
// Example 1: 
//
// 
//Input: nums = [1,2,3,1]
//Output: 4
//Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
//Total amount you can rob = 1 + 3 = 4.
// 
//
// Example 2: 
//
// 
//Input: nums = [2,7,9,3,1]
//Output: 12
//Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 
//(money = 1).
//Total amount you can rob = 2 + 9 + 1 = 12.
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 100 
// 0 <= nums[i] <= 400 
// 
//
// Related Topics 数组 动态规划 👍 2630 👎 0


#include "leetcode-base.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    /*
     * dp[i] 前i个数中，能偷到的最多的钱数是dp[i]
     *
     */
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];

        for(int i = 1; i< nums.size(); i++) {
            if(i >= 2)
                dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
            else
                dp[i] = max(nums[0], nums[1]);
        }
        return dp[nums.size()-1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    
    return 0;
}