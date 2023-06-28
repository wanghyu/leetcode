//Given an integer array nums, find the subarray with the largest sum, and 
//return its sum. 
//
// 
// Example 1: 
//
// 
//Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
//Output: 6
//Explanation: The subarray [4,-1,2,1] has the largest sum 6.
// 
//
// Example 2: 
//
// 
//Input: nums = [1]
//Output: 1
//Explanation: The subarray [1] has the largest sum 1.
// 
//
// Example 3: 
//
// 
//Input: nums = [5,4,-1,7,8]
//Output: 23
//Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 10⁵ 
// -10⁴ <= nums[i] <= 10⁴ 
// 
//
// 
// Follow up: If you have figured out the O(n) solution, try coding another 
//solution using the divide and conquer approach, which is more subtle. 
//
// Related Topics 数组 分治 动态规划 👍 6129 👎 0


#include "leetcode-base.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
//    int maxSubArray(vector<int>& nums) {
//        //暴力  超时了
//        int result = INT32_MIN;
//        int count;
//        for(int i = 0; i < nums.size(); i++) {
//            count = 0;
//            for(int j = i; j < nums.size(); j++) {
//                count += nums[j];
//                result = count > result ? count : result;
//            }
//        }
//        return result;
//    }

    //贪心
    int maxSubArray(vector<int>& nums) {
        int count = 0;
        int res = INT32_MIN;
        for(int i = 0; i< nums.size(); ++i) {
            count += nums[i];
            if(count > res) {
                res = count;
            }
            if(count < 0) {
                count = 0;
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;

    vector<int> nums{5,4,-1,7,8};
    cout << s.maxSubArray(nums) << endl;
    return 0;
}