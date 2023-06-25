//Given a string s containing just the characters '(', ')', '{', '}', '[' and ']
//', determine if the input string is valid. 
//
// An input string is valid if: 
//
// 
// Open brackets must be closed by the same type of brackets. 
// Open brackets must be closed in the correct order. 
// Every close bracket has a corresponding open bracket of the same type. 
// 
//
// 
// Example 1: 
//
// 
//Input: s = "()"
//Output: true
// 
//
// Example 2: 
//
// 
//Input: s = "()[]{}"
//Output: true
// 
//
// Example 3: 
//
// 
//Input: s = "(]"
//Output: false
// 
//
// 
// Constraints: 
//
// 
// 1 <= s.length <= 10⁴ 
// s consists of parentheses only '()[]{}'. 
// 
//
// Related Topics 栈 字符串 👍 3983 👎 0


#include "leetcode-base.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isValid(string s) {
        if(s.size() %2 != 0) return false;
        stack<char> sk;
        for(int i = 0; i< s.size(); i++) {
            if(s[i] == '(')
                sk.push(')');
            else if(s[i] == '[')
                sk.push(']');
            else if(s[i] == '{')
                sk.push('}');
            else {
                if(sk.empty() || sk.top() != s[i]) {
                    return false;
                }
                sk.pop();
            }
        }
        return sk.empty();
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    cout << s.isValid("()") << endl;
    
    return 0;
}