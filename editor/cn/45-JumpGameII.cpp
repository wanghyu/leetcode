//You are given a 0-indexed array of integers nums of length n. You are 
//initially positioned at nums[0]. 
//
// Each element nums[i] represents the maximum length of a forward jump from 
//index i. In other words, if you are at nums[i], you can jump to any nums[i + j] 
//where: 
//
// 
// 0 <= j <= nums[i] and 
// i + j < n 
// 
//
// Return the minimum number of jumps to reach nums[n - 1]. The test cases are 
//generated such that you can reach nums[n - 1]. 
//
// 
// Example 1: 
//
// 
//Input: nums = [2,3,1,1,4]
//Output: 2
//Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 
//step from index 0 to 1, then 3 steps to the last index.
// 
//
// Example 2: 
//
// 
//Input: nums = [2,3,0,1,4]
//Output: 2
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 10⁴ 
// 0 <= nums[i] <= 1000 
// It's guaranteed that you can reach nums[n - 1]. 
// 
//
// Related Topics 贪心 数组 动态规划 👍 2146 👎 0


#include "leetcode-base.h"

//统计这一步的覆盖范围和下一步的覆盖范围

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;

        int res = 0;
        int curDistance = 0;
        int nextDistance = 0;
        for(int i = 0; i <= nums.size(); i++) {
            nextDistance = max(nextDistance, nums[i] + i);
            if(i == curDistance) {
                res++;
                curDistance = nextDistance;
                if(nextDistance >= nums.size() - 1) break;
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    vector<int> nums{7,0,9,6,9,6,1,7,9,0,1,2,9,0,3};
    cout << s.jump(nums) << endl;
    return 0;
}