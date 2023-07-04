//Given a sorted array of distinct integers and a target value, return the 
//index if the target is found. If not, return the index where it would be if it were 
//inserted in order. 
//
// You must write an algorithm with O(log n) runtime complexity. 
//
// 
// Example 1: 
//
// 
//Input: nums = [1,3,5,6], target = 5
//Output: 2
// 
//
// Example 2: 
//
// 
//Input: nums = [1,3,5,6], target = 2
//Output: 1
// 
//
// Example 3: 
//
// 
//Input: nums = [1,3,5,6], target = 7
//Output: 4
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 10⁴ 
// -10⁴ <= nums[i] <= 10⁴ 
// nums contains distinct values sorted in ascending order. 
// -10⁴ <= target <= 10⁴ 
// 
//
// Related Topics 数组 二分查找 👍 2058 👎 0


#include "leetcode-base.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //二分
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int mid;
        while(left <= right) {
            mid = left + ((right - left) >> 1);
            if(nums[mid] > target) {
                right = mid - 1;
            } else if(nums[mid] < target) {
                left = mid + 1;
            } else {
                return mid;
            }
        }
        return right+1; // or return left;
    }
    //暴力
    int searchInsert3(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] >= target) return i;
        }
        return nums.size();
    }
    //库函数
    int searchInsert2(vector<int>& nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    
    return 0;
}