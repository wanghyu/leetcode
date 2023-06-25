//You are given a string s consisting of lowercase English letters. A duplicate 
//removal consists of choosing two adjacent and equal letters and removing them. 
//
// We repeatedly make duplicate removals on s until we no longer can. 
//
// Return the final string after all such duplicate removals have been made. It 
//can be proven that the answer is unique. 
//
// 
// Example 1: 
//
// 
//Input: s = "abbaca"
//Output: "ca"
//Explanation: 
//For example, in "abbaca" we could remove "bb" since the letters are adjacent 
//and equal, and this is the only possible move.  The result of this move is that 
//the string is "aaca", of which only "aa" is possible, so the final string is 
//"ca".
// 
//
// Example 2: 
//
// 
//Input: s = "azxxzy"
//Output: "ay"
// 
//
// 
// Constraints: 
//
// 
// 1 <= s.length <= 10⁵ 
// s consists of lowercase English letters. 
// 
//
// Related Topics 栈 字符串 👍 536 👎 0


#include "leetcode-base.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> sk;
        for(int i = 0; i < s.size(); i++) {
            if(!sk.empty() && sk.top() == s[i]) {
                sk.pop();
            } else {
                sk.push(s[i]);
            }
        }
        string res;
        while(!sk.empty()) {
            res += sk.top();
            sk.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;

    cout << s.removeDuplicates("abbaca") << endl;

    return 0;
}