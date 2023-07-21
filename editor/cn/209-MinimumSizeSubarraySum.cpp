//Given an array of positive integers nums and a positive integer target, 
//return the minimal length of a subarray whose sum is greater than or equal to target. 
//If there is no such subarray, return 0 instead. 
//
// 
// Example 1: 
//
// 
//Input: target = 7, nums = [2,3,1,2,4,3]
//Output: 2
//Explanation: The subarray [4,3] has the minimal length under the problem 
//constraint.
// 
//
// Example 2: 
//
// 
//Input: target = 4, nums = [1,4,4]
//Output: 1
// 
//
// Example 3: 
//
// 
//Input: target = 11, nums = [1,1,1,1,1,1,1,1]
//Output: 0
// 
//
// 
// Constraints: 
//
// 
// 1 <= target <= 10⁹ 
// 1 <= nums.length <= 10⁵ 
// 1 <= nums[i] <= 10⁴ 
// 
//
// 
//Follow up: If you have figured out the 
//O(n) solution, try coding another solution of which the time complexity is 
//O(n log(n)).
//
// Related Topics 数组 二分查找 前缀和 滑动窗口 👍 1764 👎 0


#include "leetcode-base.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //暴力 Time exceed
    int minSubArrayLen2(int target, vector<int>& nums) {
        int res = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for(int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if(sum >= target) {
                    res = min(res, j - i + 1);
                    break;
                }
            }
        }
        return res == INT_MAX ? 0:res;
    }
    //滑动窗口
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX;
        int i = 0;
        int sum = 0;
        for(int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            while(sum >= target) {
                int len = j - i + 1;
                res = min(res, len);
                sum -= nums[i++];
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    
    return 0;
}