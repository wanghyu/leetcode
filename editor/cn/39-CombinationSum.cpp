//Given an array of distinct integers candidates and a target integer target, 
//return a list of all unique combinations of candidates where the chosen numbers 
//sum to target. You may return the combinations in any order. 
//
// The same number may be chosen from candidates an unlimited number of times. 
//Two combinations are unique if the frequency of at least one of the chosen 
//numbers is different. 
//
// The test cases are generated such that the number of unique combinations 
//that sum up to target is less than 150 combinations for the given input. 
//
// 
// Example 1: 
//
// 
//Input: candidates = [2,3,6,7], target = 7
//Output: [[2,2,3],[7]]
//Explanation:
//2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple 
//times.
//7 is a candidate, and 7 = 7.
//These are the only two combinations.
// 
//
// Example 2: 
//
// 
//Input: candidates = [2,3,5], target = 8
//Output: [[2,2,2,2],[2,3,3],[3,5]]
// 
//
// Example 3: 
//
// 
//Input: candidates = [2], target = 1
//Output: []
// 
//
// 
// Constraints: 
//
// 
// 1 <= candidates.length <= 30 
// 2 <= candidates[i] <= 40 
// All elements of candidates are distinct. 
// 1 <= target <= 40 
// 
//
// Related Topics 数组 回溯 👍 2517 👎 0


#include "leetcode-base.h"

//candidates中的数字可以重复被使用

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;

    void backtrack(vector<int>& candidates, int target, int startIndex) {
        if(accumulate(path.begin(), path.end(), 0) == target) {
            res.push_back(path);
            return;
        }
        if(accumulate(path.begin(), path.end(), 0) > target) {
            return;
        }

        for(int i = startIndex; i < candidates.size(); ++i) {
            path.push_back(candidates[i]);
            backtrack(candidates, target, i); //不用i+1了，表示可以重复读取当前的数
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates, target, 0);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    
    return 0;
}