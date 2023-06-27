//Given an integer array nums, return all the different possible non-decreasing 
//subsequences of the given array with at least two elements. You may return the 
//answer in any order. 
//
// 
// Example 1: 
//
// 
//Input: nums = [4,6,7,7]
//Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
// 
//
// Example 2: 
//
// 
//Input: nums = [4,4,3,2,1]
//Output: [[4,4]]
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 15 
// -100 <= nums[i] <= 100 
// 
//
// Related Topics 位运算 数组 哈希表 回溯 👍 672 👎 0


#include "leetcode-base.h"

//不能再排序然后去重了
//同一层不能重复

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;

    void backtrack(vector<int>& nums, int startIndex) {
        if(path.size() >= 2) {
            res.push_back(path);
        }

        unordered_set<int> uset;
        for(int i = startIndex; i< nums.size(); ++i) {
//            if((!path.empty() && nums[i] >= path.back()) || uset.find(nums[i]) == uset.end() || path.empty()) {
//                uset.insert(nums[i]);
//                path.push_back(nums[i]);
//                backtrack(nums, i+1);
//                path.pop_back();
//            }
            if ((!path.empty() && nums[i] < path.back())
                || uset.find(nums[i]) != uset.end()) {
                continue;
            }
            uset.insert(nums[i]); // 记录这个元素在本层用过了，本层后面不能再用了
            path.push_back(nums[i]);
            backtrack(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtrack(nums, 0);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    vector<int> nums{4,6,7,7};
    auto res = s.findSubsequences(nums);
    printVecVec(res);
    return 0;
}