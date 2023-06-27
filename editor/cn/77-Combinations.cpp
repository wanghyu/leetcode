//Given two integers n and k, return all possible combinations of k numbers 
//chosen from the range [1, n]. 
//
// You may return the answer in any order. 
//
// 
// Example 1: 
//
// 
//Input: n = 4, k = 2
//Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
//Explanation: There are 4 choose 2 = 6 total combinations.
//Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to 
//be the same combination.
// 
//
// Example 2: 
//
// 
//Input: n = 1, k = 1
//Output: [[1]]
//Explanation: There is 1 choose 1 = 1 total combination.
// 
//
// 
// Constraints: 
//
// 
// 1 <= n <= 20 
// 1 <= k <= n 
// 
//
// Related Topics 回溯 👍 1410 👎 0


#include "leetcode-base.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;


    void backtracking(int n, int k, int startIndex) {
        if(path.size() == k) {
            res.push_back(path);
            return;
        }

        for(int i = startIndex; i <= n; i++) {
            path.push_back(i);
            backtracking(n, k, i+1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return res;
    }

};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    
    return 0;
}