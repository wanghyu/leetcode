//You are given an array of binary strings strs and two integers m and n. 
//
// Return the size of the largest subset of strs such that there are at most m 0
//'s and n 1's in the subset. 
//
// A set x is a subset of a set y if all elements of x are also elements of y. 
//
// 
// Example 1: 
//
// 
//Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
//Output: 4
//Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001",
// "1", "0"}, so the answer is 4.
//Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
//{"111001"} is an invalid subset because it contains 4 1's, greater than the 
//maximum of 3.
// 
//
// Example 2: 
//
// 
//Input: strs = ["10","0","1"], m = 1, n = 1
//Output: 2
//Explanation: The largest subset is {"0", "1"}, so the answer is 2.
// 
//
// 
// Constraints: 
//
// 
// 1 <= strs.length <= 600 
// 1 <= strs[i].length <= 100 
// strs[i] consists only of digits '0' and '1'. 
// 1 <= m, n <= 100 
// 
//
// Related Topics 数组 字符串 动态规划 👍 989 👎 0


#include "leetcode-base.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //dp[i][j] i个0  j个1 最大的子集大小为dp[i][j]
    // dp[i][j] = dp[i-zeroNum][j-oneNum] + 1
    //dp[0][0] = 0;
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        dp[0][0] = 0;

        for(auto str : strs) {
            int zeroNum = 0;
            int oneNum = 0;
            for(auto c : str) {
                if(c == '0') zeroNum++;
                else oneNum++;
            }

            for(int i = m; i >= zeroNum; i--) {
                for(int j = n; j >= oneNum; j--) {
                    dp[i][j] = max(dp[i][j], dp[i-zeroNum][j-oneNum]+1);
                }
            }
            //printVecVec(dp);
        }
        return dp[m][n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    vector<string> strs{"10","0001","111001","1","0"};
    cout << s.findMaxForm(strs, 3,3) << endl;
    return 0;
}