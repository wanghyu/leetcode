//Your friend is typing his name into a keyboard. Sometimes, when typing a 
//character c, the key might get long pressed, and the character will be typed 1 or 
//more times. 
//
// You examine the typed characters of the keyboard. Return True if it is 
//possible that it was your friends name, with some characters (possibly none) being 
//long pressed. 
//
// 
// Example 1: 
//
// 
//Input: name = "alex", typed = "aaleex"
//Output: true
//Explanation: 'a' and 'e' in 'alex' were long pressed.
// 
//
// Example 2: 
//
// 
//Input: name = "saeed", typed = "ssaaedd"
//Output: false
//Explanation: 'e' must have been pressed twice, but it was not in the typed 
//output.
// 
//
// 
// Constraints: 
//
// 
// 1 <= name.length, typed.length <= 1000 
// name and typed consist of only lowercase English letters. 
// 
//
// Related Topics 双指针 字符串 👍 280 👎 0


#include "leetcode-base.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int slow = 0, fast = 0;
        for(;slow < name.size() && fast < typed.size(); fast++) {
            if(typed[fast] == name[slow]) {
                slow++;
            } else {
                if(fast > 0 && typed[fast] == typed[fast-1]) {
                    continue;
                } else {
                    return false;
                }
            }
        }
        if(slow == name.size()) {
            if(fast < typed.size()) {
                for(; fast < typed.size(); fast++) {
                    if(typed[fast] != typed[fast-1]) {
                        return false;
                    }
                }
            }
            return true;
        } else {
            return false;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    cout << s.isLongPressedName("alex", "aaleexa") << endl;
    return 0;
}