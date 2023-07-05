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

        vector<int> vec(200);
        for(int i = 0; i < s.size(); i++) {
            if(vec[s[i]] != 0) {
                if( vec[s[i]] != t[i] )
                    return false;
            } else {
                vec[s[i]] = t[i];
            }
        }

        vec.clear();
        vec.resize(200);
        for(int i = 0; i < s.size(); i++) {
            if(vec[t[i]] != 0) {
                if( vec[t[i]] != s[i] )
                    return false;
            } else {
                vec[t[i]] = s[i];
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