//Given an integer array nums, return true if you can partition the array into 
//two subsets such that the sum of the elements in both subsets is equal or false 
//otherwise. 
//
// 
// Example 1: 
//
// 
//Input: nums = [1,5,11,5]
//Output: true
//Explanation: The array can be partitioned as [1, 5, 5] and [11].
// 
//
// Example 2: 
//
// 
//Input: nums = [1,2,3,5]
//Output: false
//Explanation: The array cannot be partitioned into equal sum subsets.
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 200 
// 1 <= nums[i] <= 100 
// 
//
// Related Topics 数组 动态规划 👍 1794 👎 0


#include "leetcode-base.h"

//dp[i][j]

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    bool find = false;
    void backtrack(vector<int>& nums, int target, int sum, int startIndex) {
        if(sum == target) {
            find = true;
            return;
        }
        if(sum > target) {
            return;
        }

        for(int i = startIndex; i < nums.size(); i++) {
            sum += nums[i];
            backtrack(nums, target, sum, i+1);
            sum -= nums[i];
        }
    }
public:
    bool canPartition3(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 || nums.size() == 1) return false;
        int target = sum / 2;

        int s = 0;
        backtrack(nums, target, s, 0);
        return find;
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 || nums.size() == 1) return false;
        int target = sum / 2;
        //背包最大容量是j， 装上物品后最大价值是dp[j]
        vector<int> dp(target + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = target; j >= nums[i]; j--) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        return dp[target] == target;
    }


    bool canPartition2(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 || nums.size() == 1) return false;

        int target = sum / 2;
        vector<vector<int>> dp(nums.size(), vector<int>(target+1, 0));

        for(int j = 0; j <= target; j++) {
            if(j >= nums[0]) {
                dp[0][j] = nums[0];
            }
        }

        for(int i = 1; i < nums.size(); i++) {
            for(int j = 0; j <= target; j++) {
                if(j < nums[i]) dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-nums[i]] + nums[i]);
            }
        }
//        printVecVec(dp);

        if(dp[nums.size()-1][target] == target)
            return true;

        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    vector<int> nums{1,2,3,5};
    //vector<int> nums{100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,99,97};
    cout << s.canPartition(nums) << endl;
    cout << s.canPartition3(nums) << endl;
    return 0;
}