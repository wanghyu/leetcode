//Given a string s, partition s such that every substring of the partition is a 
//palindrome. Return all possible palindrome partitioning of s. 
//
// 
// Example 1: 
// Input: s = "aab"
//Output: [["a","a","b"],["aa","b"]]
// 
// Example 2: 
// Input: s = "a"
//Output: [["a"]]
// 
// 
// Constraints: 
//
// 
// 1 <= s.length <= 16 
// s contains only lowercase English letters. 
// 
//
// Related Topics 字符串 动态规划 回溯 👍 1542 👎 0


#include "leetcode-base.h"

//切割
//判断回文

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<string>> res;
    vector<string> path;

    bool isPalindrome(const string& s, int start, int end) {
        for(int i =  start, j = end; i < j; i++, j--) {
            if(s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }

    void backtrack(string& s, int startIndex) {
        if(startIndex == s.size()) {
            res.push_back(path);
            return;
        }

        for(int i = startIndex; i < s.size(); i++) {
            if(isPalindrome(s, startIndex, i)) {
                string str = s.substr(startIndex, i-startIndex + 1);
                path.push_back(str);
            } else {
                continue;
            }

            backtrack(s, i+1);
            path.pop_back();
        }
    }
public:
    vector<vector<string>> partition(string s) {
        backtrack(s, 0);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    [[maybe_unused]] Solution s;
    auto res = s.partition("aab");
    printVecVec(res);
    
    return 0;
}