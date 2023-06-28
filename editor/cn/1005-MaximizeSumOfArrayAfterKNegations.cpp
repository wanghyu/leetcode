//Given an integer array nums and an integer k, modify the array in the 
//following way: 
//
// 
// choose an index i and replace nums[i] with -nums[i]. 
// 
//
// You should apply this process exactly k times. You may choose the same index 
//i multiple times. 
//
// Return the largest possible sum of the array after modifying it in this way. 
//
//
// 
// Example 1: 
//
// 
//Input: nums = [4,2,3], k = 1
//Output: 5
//Explanation: Choose index 1 and nums becomes [4,-2,3].
// 
//
// Example 2: 
//
// 
//Input: nums = [3,-1,0,2], k = 3
//Output: 6
//Explanation: Choose indices (1, 2, 2) and nums becomes [3,1,0,2].
// 
//
// Example 3: 
//
// 
//Input: nums = [2,-3,-1,5,-4], k = 2
//Output: 13
//Explanation: Choose indices (1, 4) and nums becomes [2,3,-1,5,4].
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 10⁴ 
// -100 <= nums[i] <= 100 
// 1 <= k <= 10⁴ 
// 
//
// Related Topics 贪心 数组 排序 👍 366 👎 0


#include "leetcode-base.h"

//按照绝对值大小排序

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return abs(a) > abs(b);
        }); //从小到大

        for(size_t i = 0; i < nums.size(); i++) {
            if(nums[i] < 0 && k > 0) {
                nums[i] *= -1;
                --k;
            }
        }

        if(k%2) { //奇数
            nums[nums.size()-1] = -1 * nums[nums.size()-1];
        }

        return accumulate(nums.begin(), nums.end(), 0);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    vector<int> nums{3,-1,0,2};
    cout << s.largestSumAfterKNegations(nums, 3) << endl;
    return 0;
}