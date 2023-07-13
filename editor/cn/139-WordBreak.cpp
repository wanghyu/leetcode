//Given a string s and a dictionary of strings wordDict, return true if s can 
//be segmented into a space-separated sequence of one or more dictionary words. 
//
// Note that the same word in the dictionary may be reused multiple times in 
//the segmentation. 
//
// 
// Example 1: 
//
// 
//Input: s = "leetcode", wordDict = ["leet","code"]
//Output: true
//Explanation: Return true because "leetcode" can be segmented as "leet code".
// 
//
// Example 2: 
//
// 
//Input: s = "applepenapple", wordDict = ["apple","pen"]
//Output: true
//Explanation: Return true because "applepenapple" can be segmented as "apple 
//pen apple".
//Note that you are allowed to reuse a dictionary word.
// 
//
// Example 3: 
//
// 
//Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
//Output: false
// 
//
// 
// Constraints: 
//
// 
// 1 <= s.length <= 300 
// 1 <= wordDict.length <= 1000 
// 1 <= wordDict[i].length <= 20 
// s and wordDict[i] consist of only lowercase English letters. 
// All the strings of wordDict are unique. 
// 
//
// Related Topics 字典树 记忆化搜索 数组 哈希表 字符串 动态规划 👍 2188 👎 0


#include "leetcode-base.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    /*
     * 完全背包
     * dp[j]  string s的前j的字符，能被wordDict 分割
     */
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        unordered_set<string> uSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(n+1, false);
        dp[0] = true;

        //顺序不能颠倒
        for(int i = 1; i <= n; i++) { //先遍历背包
            for(int j = 0; j < i; j++) {
                string str = s.substr(j, i-j);
                if(uSet.find(str) != uSet.end() && dp[j]) {
                    dp[i] = true;
                }
            }
        }
        return dp[n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    
    return 0;
}