//Given an array nums of distinct integers, return all the possible 
//permutations. You can return the answer in any order. 
//
// 
// Example 1: 
// Input: nums = [1,2,3]
//Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// 
// Example 2: 
// Input: nums = [0,1]
//Output: [[0,1],[1,0]]
// 
// Example 3: 
// Input: nums = [1]
//Output: [[1]]
// 
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 6 
// -10 <= nums[i] <= 10 
// All the integers of nums are unique. 
// 
//
// Related Topics 数组 回溯 👍 2588 👎 0


#include "leetcode-base.h"

//全排列  不包含重复元素

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;

    void backtrack(vector<int>& nums, vector<bool> used) {
        if(path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(used[i]) continue;

            used[i] = true;
            path.push_back(nums[i]);
            backtrack(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        backtrack(nums, used);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    vector<int> nums{1,2,3};
    auto res = s.permute(nums);
    printVecVec(res);
    
    return 0;
}