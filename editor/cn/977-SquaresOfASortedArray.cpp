//Given an integer array nums sorted in non-decreasing order, return an array 
//of the squares of each number sorted in non-decreasing order. 
//
// 
// Example 1: 
//
// 
//Input: nums = [-4,-1,0,3,10]
//Output: [0,1,9,16,100]
//Explanation: After squaring, the array becomes [16,1,0,9,100].
//After sorting, it becomes [0,1,9,16,100].
// 
//
// Example 2: 
//
// 
//Input: nums = [-7,-3,2,3,11]
//Output: [4,9,9,49,121]
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 10⁴ 
// -10⁴ <= nums[i] <= 10⁴ 
// nums is sorted in non-decreasing order. 
// 
//
// 
//Follow up: Squaring each element and sorting the new array is very trivial, 
//could you find an 
//O(n) solution using a different approach?
//
// Related Topics 数组 双指针 排序 👍 835 👎 0


#include "leetcode-base.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    static bool cmp(int a, int b) {
        return abs(a) < abs(b);
    }
public:
    vector<int> sortedSquares2(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        for(int i = 0; i < nums.size(); i++) {
            nums[i] *= nums[i];
        }
        return nums;
    }

    vector<int> sortedSquares(vector<int>& nums) {
        int i = 0;
        int j = nums.size()-1;
        int k = nums.size()-1;
        vector<int> res(nums.size(), 0);

        for(; k >= 0; ) {
            if(nums[i] * nums[i] <= nums[j] * nums[j]) {
                res[k--] = nums[j] * nums[j];
                j--;
            } else if(nums[i] * nums[i] > nums[j] * nums[j]) {
                res[k--] = nums[i] * nums[i];
                i++;
            }
        }
        return res;
    }

};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    vector<int> nums{-4,-1,0,3,10};
    auto vec = s.sortedSquares(nums);
    printVec(vec);
    return 0;
}