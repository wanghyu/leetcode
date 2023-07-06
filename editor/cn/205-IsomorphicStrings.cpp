//Given two strings s and t, determine if they are isomorphic. 
//
// Two strings s and t are isomorphic if the characters in s can be replaced to 
//get t. 
//
// All occurrences of a character must be replaced with another character while 
//preserving the order of characters. No two characters may map to the same 
//character, but a character may map to itself. 
//
// 
// Example 1: 
// Input: s = "egg", t = "add"
//Output: true
// 
// Example 2: 
// Input: s = "foo", t = "bar"
//Output: false
// 
// Example 3: 
// Input: s = "paper", t = "title"
//Output: true
// 
// 
// Constraints: 
//
// 
// 1 <= s.length <= 5 * 10⁴ 
// t.length == s.length 
// s and t consist of any valid ascii character. 
// 
//
// Related Topics 哈希表 字符串 👍 615 👎 0


#include "leetcode-base.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;

        unordered_map<char, char> map1;
        unordered_map<char, char> map2;
        for(int i = 0; i < s.size(); i++) {
            if(map1.find(s[i]) == map1.end()) {
                map1[s[i]] = t[i];
            }

            if(map2.find(t[i]) == map2.end()) {
                map2[t[i]] = s[i];
            }

            if(map1[s[i]] != t[i] || map2[t[i]] != s[i]) {
                return false;
            }
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    cout << s.isIsomorphic("paper", "title") << endl;
    return 0;
}