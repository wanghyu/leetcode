//You are given an integer array nums and an integer target. 
//
// You want to build an expression out of nums by adding one of the symbols '+' 
//and '-' before each integer in nums and then concatenate all the integers. 
//
// 
// For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 
//and concatenate them to build the expression "+2-1". 
// 
//
// Return the number of different expressions that you can build, which 
//evaluates to target. 
//
// 
// Example 1: 
//
// 
//Input: nums = [1,1,1,1,1], target = 3
//Output: 5
//Explanation: There are 5 ways to assign symbols to make the sum of nums be 
//target 3.
//-1 + 1 + 1 + 1 + 1 = 3
//+1 - 1 + 1 + 1 + 1 = 3
//+1 + 1 - 1 + 1 + 1 = 3
//+1 + 1 + 1 - 1 + 1 = 3
//+1 + 1 + 1 + 1 - 1 = 3
// 
//
// Example 2: 
//
// 
//Input: nums = [1], target = 1
//Output: 1
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 20 
// 0 <= nums[i] <= 1000 
// 0 <= sum(nums[i]) <= 1000 
// -1000 <= target <= 1000 
// 
//
// Related Topics 数组 动态规划 回溯 👍 1665 👎 0


#include "leetcode-base.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<int> path;
    int res = 0;
    void backtrack(vector<int>& nums, int target, int sum, int startIndex) {
        if(sum == target) {
            res++;
        }
        for(int i = startIndex; i < nums.size() && sum + nums[i] <= target; i++) {
            path.push_back(nums[i]);
            sum += nums[i];
            backtrack(nums, target, sum, i+1);
            sum -= nums[i];
            path.pop_back();
        }
    }
public:
    //left - right = target; left + right = sum; -> left - (sum - left) = target;  left = (sum + target) / 2
    int findTargetSumWays2(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(target > sum) return 0;
        if((sum + target) % 2) return 0;
        int left = (sum + target) / 2;

        sort(nums.begin(), nums.end()); //防止 {1, 0} 这种
        backtrack(nums, left, 0, 0);
        return res;
    }

    /*
     * dp[j] 装满j容积的背包，有dp[j]种方法
     * 有一个1的情况下，有dp[4]
     * 有一个2的情况下，有dp[3]
     * ....
     *
     * dp[j] += dp[j-nums[i]
     */
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(abs(target) > sum) return 0;
        if((sum + target) % 2) return 0;
        int x = (sum + target) / 2;

        vector<int> dp(x+1, 0);
        dp[0] = 1;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = x; j >= nums[i]; j--) {
                dp[j] += dp[j-nums[i]];
            }
        }
        return dp[x];
    }


};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    
    return 0;
}