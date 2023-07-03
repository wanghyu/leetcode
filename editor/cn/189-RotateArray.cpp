//Given an integer array nums, rotate the array to the right by k steps, where 
//k is non-negative. 
//
// 
// Example 1: 
//
// 
//Input: nums = [1,2,3,4,5,6,7], k = 3
//Output: [5,6,7,1,2,3,4]
//Explanation:
//rotate 1 steps to the right: [7,1,2,3,4,5,6]
//rotate 2 steps to the right: [6,7,1,2,3,4,5]
//rotate 3 steps to the right: [5,6,7,1,2,3,4]
// 
//
// Example 2: 
//
// 
//Input: nums = [-1,-100,3,99], k = 2
//Output: [3,99,-1,-100]
//Explanation: 
//rotate 1 steps to the right: [99,-1,-100,3]
//rotate 2 steps to the right: [3,99,-1,-100]
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 10⁵ 
// -2³¹ <= nums[i] <= 2³¹ - 1 
// 0 <= k <= 10⁵ 
// 
//
// 
// Follow up: 
//
// 
// Try to come up with as many solutions as you can. There are at least three 
//different ways to solve this problem. 
// Could you do it in-place with O(1) extra space? 
// 
//
// Related Topics 数组 数学 双指针 👍 1867 👎 0


#include "leetcode-base.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin()+k, nums.end());
    }

    void rotate2(vector<int>& nums, int k) {
        int size = nums.size();
        for(int i = 0; i < size; i++) {
            nums.push_back(nums[i]);
        }

        k = k % size;

        int index = nums.size() - size;
        for(int i= 0; i <k; i++) {
            index--;
        }

        for(int i = 0; i < size; i++)
        {
            nums[i] = nums[index++];
        }

        nums.resize(size);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    vector<int> nums{1,2,3,4,5,6,7};
    s.rotate(nums, 3);
    printVec(nums);
    return 0;
}