//Given a collection of numbers, nums, that might contain duplicates, return 
//all possible unique permutations in any order. 
//
// 
// Example 1: 
//
// 
//Input: nums = [1,1,2]
//Output:
//[[1,1,2],
// [1,2,1],
// [2,1,1]]
// 
//
// Example 2: 
//
// 
//Input: nums = [1,2,3]
//Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 8 
// -10 <= nums[i] <= 10 
// 
//
// Related Topics 数组 回溯 👍 1388 👎 0


#include "leetcode-base.h"

//全排列  包含重复元素

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
            //树枝去重
            if(used[i]) continue;
            //数层去重
            if(i >0 && nums[i] == nums[i-1] && !used[i-1] ) {
                continue;
            }

            path.push_back(nums[i]);
            used[i] = true;
            backtrack(nums, used);
            used[i] = false;
            path.pop_back();
        }

    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtrack(nums, used);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    vector<int> nums{1,2,3};
    auto res = s.permuteUnique(nums);
    printVecVec(res);
    
    return 0;
}