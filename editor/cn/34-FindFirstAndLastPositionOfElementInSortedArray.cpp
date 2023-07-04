//Given an array of integers nums sorted in non-decreasing order, find the 
//starting and ending position of a given target value. 
//
// If target is not found in the array, return [-1, -1]. 
//
// You must write an algorithm with O(log n) runtime complexity. 
//
// 
// Example 1: 
// Input: nums = [5,7,7,8,8,10], target = 8
//Output: [3,4]
// 
// Example 2: 
// Input: nums = [5,7,7,8,8,10], target = 6
//Output: [-1,-1]
// 
// Example 3: 
// Input: nums = [], target = 0
//Output: [-1,-1]
// 
// 
// Constraints: 
//
// 
// 0 <= nums.length <= 10⁵ 
// -10⁹ <= nums[i] <= 10⁹ 
// nums is a non-decreasing array. 
// -10⁹ <= target <= 10⁹ 
// 
//
// Related Topics 数组 二分查找 👍 2351 👎 0


#include "leetcode-base.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    /*
     * 1. target在左边 或者右边 直接返回 -1 -1
     * 2. target在范围中，但是不存在 -1 -1
     * 3. target在范围中 并且存在
     */

    //返回右边界 [3,3] 2  target在左边 返回-2
    int getRightOrder(vector<int>& nums, int target) {
        int left =0, right = nums.size() - 1, mid;
        int rightOrder = -2;

        while(left <= right) {
            mid = left + ((right - left) >> 1);
            if(nums[mid] > target) {
                right = mid - 1;
            } else if(nums[mid] < target) {
                left = mid + 1;
                rightOrder = left;
            } else {
                left = mid + 1; //因为要得到右边界，所以不能停止，要继续找
                rightOrder = left;
            }
        }
        return rightOrder;
    }

    //返回左边界  [3,3] 4 target在右边， 返回-2
    int getLeftOrder(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1, mid;
        int leftOrder = -2;

        while(left <= right) {
            mid = left + ((right - left) >> 1);
            if(nums[mid] > target) {
                right = mid - 1;
                leftOrder = right;
            } else if(nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
                leftOrder = right;
            }
        }
        return leftOrder;
    }

    vector<int> searchRange2(vector<int>& nums, int target) {
        int left = getLeftOrder(nums, target);
        int right = getRightOrder(nums, target);

        //情况1
        if(left == -2 || right == -2)  return {-1, -1};
        //情况3
        if(right - left > 1) return {left+1, right-1};
        //情况2 right - left == 1
        return {-1, -1};
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    vector<int> nums{5,7,7,8,8,10};
    int target = 1;
    cout << lower_bound(nums.begin(), nums.end(), target) - nums.begin() << endl;
    cout << upper_bound(nums.begin(), nums.end(), target) - nums.begin() << endl;

    cout << s.getLeftOrder(nums, target) << " " << s.getRightOrder(nums, target) << endl;
    return 0;
}