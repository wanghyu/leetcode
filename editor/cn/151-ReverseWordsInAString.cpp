//Given an input string s, reverse the order of the words. 
//
// A word is defined as a sequence of non-space characters. The words in s will 
//be separated by at least one space. 
//
// Return a string of the words in reverse order concatenated by a single space.
// 
//
// Note that s may contain leading or trailing spaces or multiple spaces 
//between two words. The returned string should only have a single space separating the 
//words. Do not include any extra spaces. 
//
// 
// Example 1: 
//
// 
//Input: s = "the sky is blue"
//Output: "blue is sky the"
// 
//
// Example 2: 
//
// 
//Input: s = "  hello world  "
//Output: "world hello"
//Explanation: Your reversed string should not contain leading or trailing 
//spaces.
// 
//
// Example 3: 
//
// 
//Input: s = "a good   example"
//Output: "example good a"
//Explanation: You need to reduce multiple spaces between two words to a single 
//space in the reversed string.
// 
//
// 
// Constraints: 
//
// 
// 1 <= s.length <= 10⁴ 
// s contains English letters (upper-case and lower-case), digits, and spaces ' 
//'. 
// There is at least one word in s. 
// 
//
// 
// Follow-up: If the string data type is mutable in your language, can you 
//solve it in-place with O(1) extra space? 
//
// Related Topics 双指针 字符串 👍 901 👎 0


#include "leetcode-base.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    void removeExtraSpace2(string& s) {
        //删除多余的空格
        for(int i = s.size()-1; i > 0; i--) {
            if(s[i] == s[i-1] && s[i] == ' ') {
                s.erase(s.begin() + i);
            }
        }

        //删除前面的
        if(s.size() > 0 && s[0] == ' ')
            s.erase(s.begin());

        if(s.size() > 0 && s[s.size()-1] == ' ') {
            s.erase(s.begin() + s.size()-1);
        }
    }

    void removeExtraSpace(string& s) {
        int slow = 0, fast = 0;
        //去除前面的
        while(fast < s.size() && s[fast] == ' ') {
            fast++;
        }

        for(; fast < s.size(); fast++) {
            if(fast > 1 && s[fast] == s[fast-1] && s[fast-1] == ' ') {
                continue;
            } else {
                s[slow++] = s[fast];
            }
        }

        if(slow > 1 && s[slow-1] == ' ') {
            s.resize(slow-1);
        } else {
            s.resize(slow);
        }
    }




    void removeExtraSpace3(string& str) {
        int slow = 0;
        for(int i = 0; i < str.size(); ++i) {
            if(str[i] != ' ') {
                if(slow != 0) str[slow++] = ' ';
                while(i < str.size() && str[i] != ' ') {
                    str[slow++] = str[i++];
                }
            }
        }

        str.resize(slow);
    }
public:
    string reverseWords(string s) {
        removeExtraSpace(s);
        reverse(s.begin(), s.end());

        int start = 0;
        for(int i = 0; i <= s.size(); i++) {
            if(i == s.size()) {
                reverse(s.begin()+start, s.end());
            }
            if(s[i] ==' ') {
                reverse(s.begin()+start, s.begin() + i);
                start = i+1;
            }
        }

       return s;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    cout << s.reverseWords("the sky is blue") << endl;

    return 0;
}