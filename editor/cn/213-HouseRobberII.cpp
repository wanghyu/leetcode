//You are a professional robber planning to rob houses along a street. Each 
//house has a certain amount of money stashed. All houses at this place are arranged 
//in a circle. That means the first house is the neighbor of the last one. 
//Meanwhile, adjacent houses have a security system connected, and it will automatically 
//contact the police if two adjacent houses were broken into on the same night. 
//
// Given an integer array nums representing the amount of money of each house, 
//return the maximum amount of money you can rob tonight without alerting the 
//police. 
//
// 
// Example 1: 
//
// 
//Input: nums = [2,3,2]
//Output: 3
//Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 
//2), because they are adjacent houses.
// 
//
// Example 2: 
//
// 
//Input: nums = [1,2,3,1]
//Output: 4
//Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
//Total amount you can rob = 1 + 3 = 4.
// 
//
// Example 3: 
//
// 
//Input: nums = [1,2,3]
//Output: 3
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 100 
// 0 <= nums[i] <= 1000 
// 
//
// Related Topics 数组 动态规划 👍 1392 👎 0


#include "leetcode-base.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    /*
     * dp[i] 表示前i个数组的最大盗窃额 dp[i]
     * 从哪开始盗窃呢？最大的数开始
     * dp[i] = max(dp[i-1], dp[i-2] + nums[i])
     *
     */

    int robRange(vector<int>& nums, int start, int end) {
        vector<int> dp(nums.size(), 0);
        dp[start] = nums[start];
        for(int i = start+1; i <= end; i++) {
            if(i >= start + 2) {
                dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
            } else {
                dp[i] = max(nums[start], nums[start+1]);
            }
        }
        return dp[end];
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int res1 = robRange(nums, 0, nums.size()-2);
        int res2 = robRange(nums, 1, nums.size()-1);
        return max(res1, res2);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    
    return 0;
}