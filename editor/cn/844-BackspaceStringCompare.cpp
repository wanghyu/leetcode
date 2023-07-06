//Given two strings s and t, return true if they are equal when both are typed 
//into empty text editors. '#' means a backspace character. 
//
// Note that after backspacing an empty text, the text will continue empty. 
//
// 
// Example 1: 
//
// 
//Input: s = "ab#c", t = "ad#c"
//Output: true
//Explanation: Both s and t become "ac".
// 
//
// Example 2: 
//
// 
//Input: s = "ab##", t = "c#d#"
//Output: true
//Explanation: Both s and t become "".
// 
//
// Example 3: 
//
// 
//Input: s = "a#c", t = "b"
//Output: false
//Explanation: s becomes "c" while t becomes "b".
// 
//
// 
// Constraints: 
//
// 
// 1 <= s.length, t.length <= 200 
// s and t only contain lowercase letters and '#' characters. 
// 
//
// 
// Follow up: Can you solve it in O(n) time and O(1) space? 
//
// Related Topics 栈 双指针 字符串 模拟 👍 644 👎 0


#include "leetcode-base.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size()-1;
        int j = t.size()-1;
        int skipS = 0;
        int skipT = 0;
        while(1) {
            while(i >= 0) {
                if(s[i] == '#') skipS++;
                else {
                    if(skipS>0) skipS--;
                    else
                        break;
                }
                i--;
            }

            while(j >= 0) {
                if(t[j] == '#') skipT++;
                else {
                    if(skipT > 0) skipT--;
                    else
                        break;
                }
                j--;
            }

            if(i < 0 || j < 0) break;

            if(s[i] != t[j]) return false;
            i--;j--;
        }

        if(i == -1 && j == -1) return true;
        return false;
    }


    bool backspaceCompare2(string s, string t) {
        string s1;
        string s2;
        for(auto ch : s) {
            if(ch == '#') {
                if(!s1.empty())
                    s1.pop_back();
            } else
                s1.push_back(ch);
        }

        for(auto ch : t) {
            if(ch == '#') {
                if(!s2.empty())
                    s2.pop_back();
            } else
                s2.push_back(ch);
        }
        return s1 == s2;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    cout << s.backspaceCompare("ab#c", "ad#c") << endl;
    
    return 0;
}