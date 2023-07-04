//Given an array of integers nums, half of the integers in nums are odd, and 
//the other half are even. 
//
// Sort the array so that whenever nums[i] is odd, i is odd, and whenever nums[
//i] is even, i is even. 
//
// Return any answer array that satisfies this condition. 
//
// 
// Example 1: 
//
// 
//Input: nums = [4,2,5,7]
//Output: [4,5,2,7]
//Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.
// 
//
// Example 2: 
//
// 
//Input: nums = [2,3]
//Output: [2,3]
// 
//
// 
// Constraints: 
//
// 
// 2 <= nums.length <= 2 * 10⁴ 
// nums.length is even. 
// Half of the integers in nums are even. 
// 0 <= nums[i] <= 1000 
// 
//
// 
// Follow Up: Could you solve it in-place? 
//
// Related Topics 数组 双指针 排序 👍 271 👎 0


#include "leetcode-base.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int odd = 1;
        int even = 0;
        vector<int> res(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] % 2) {
                res[odd] = nums[i];
                odd +=2;
            } else {
                res[even] = nums[i];
                even +=2;
            }
        }
        return res;
    }

    vector<int> sortArrayByParityII2(vector<int>& nums) {
        int slow = 0;
        for(int fast = 0; fast < nums.size(); fast = fast+2) {
            if(nums[fast] % 2 != 0) {
                for(slow = 1; slow < nums.size();slow = slow+2) {
                    if(nums[slow] % 2 == 0) {
                        swap(nums[fast], nums[slow]);
                        break;
                    }
                }
            }
        }

        for(int fast = 1; fast < nums.size(); fast = fast + 2) {
            if(nums[fast] % 2 == 0) {
                for(slow = 0; slow < nums.size(); slow = slow + 2) {
                    if(nums[slow] % 2) {
                        swap(nums[fast], nums[slow]);
                        break;
                    }
                }
            }
        }
        return nums;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    vector<int> nums{4,2,5,7};
    auto res = s.sortArrayByParityII(nums);
    printVec(res);
    return 0;
}