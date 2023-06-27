//Given an integer array nums that may contain duplicates, return all possible 
//subsets (the power set). 
//
// The solution set must not contain duplicate subsets. Return the solution in 
//any order. 
//
// 
// Example 1: 
// Input: nums = [1,2,2]
//Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
// 
// Example 2: 
// Input: nums = [0]
//Output: [[],[0]]
// 
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 10 
// -10 <= nums[i] <= 10 
// 
//
// Related Topics 位运算 数组 回溯 👍 1117 👎 0


#include "leetcode-base.h"

//子集问题
//包含重复元素  去重

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;

    void backtrack(vector<int>& nums, int startIndex, vector<bool> used) {
        res.push_back(path);

        for(int i = startIndex; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i-1] && used[i-1] == false) {
                continue;
            }

            path.push_back(nums[i]);
            used[i] = true;
            backtrack(nums, i+1, used);
            used[i] = false;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, used);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    vector<int> nums{1,2,2};
    auto res = s.subsetsWithDup(nums);
    printVecVec(res);
    
    return 0;
}