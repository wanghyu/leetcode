//Given a collection of candidate numbers (candidates) and a target number (
//target), find all unique combinations in candidates where the candidate numbers sum 
//to target. 
//
// Each number in candidates may only be used once in the combination. 
//
// Note: The solution set must not contain duplicate combinations. 
//
// 
// Example 1: 
//
// 
//Input: candidates = [10,1,2,7,6,1,5], target = 8
//Output: 
//[
//[1,1,6],
//[1,2,5],
//[1,7],
//[2,6]
//]
// 
//
// Example 2: 
//
// 
//Input: candidates = [2,5,2,1,2], target = 5
//Output: 
//[
//[1,2,2],
//[5]
//]
// 
//
// 
// Constraints: 
//
// 
// 1 <= candidates.length <= 100 
// 1 <= candidates[i] <= 50 
// 1 <= target <= 30 
// 
//
// Related Topics 数组 回溯 👍 1367 👎 0


#include "leetcode-base.h"

//candidates中有重复的数 需要去重
//candidates中的数只能被选用一次

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    int sum;

    void backtrack(vector<int>& candidates, int target, int sum, int startIndex, vector<bool>& used) {
        if(sum == target) {
            res.push_back(path);
            return;
        }
        if(sum > target) {
            return;
        }

        for(int i = startIndex; i < candidates.size(); ++i) {
            //数层去重
            if(i > 0 && candidates[i] == candidates[i-1] && used[i-1] == false) {
                continue;
            }

            used[i] = true;
            path.push_back(candidates[i]);
            sum += candidates[i];
            backtrack(candidates, target, sum, i+1, used);
            used[i] = false;
            sum -= candidates[i];
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, 0, used);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    
    return 0;
}