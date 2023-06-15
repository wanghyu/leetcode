//Write a function that reverses a string. The input string is given as an 
//array of characters s. 
//
// You must do this by modifying the input array in-place with O(1) extra 
//memory. 
//
// 
// Example 1: 
// Input: s = ["h","e","l","l","o"]
//Output: ["o","l","l","e","h"]
// 
// Example 2: 
// Input: s = ["H","a","n","n","a","h"]
//Output: ["h","a","n","n","a","H"]
// 
// 
// Constraints: 
//
// 
// 1 <= s.length <= 10⁵ 
// s[i] is a printable ascii character. 
// 
//
// Related Topics 双指针 字符串 👍 776 👎 0


#include "leetcode-base.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0, j = s.size()-1;
        while(i < j) {
            swap(s[i++], s[j--]);
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    vector<char> vec{'h', 'e','l','l', 'o'};
    s.reverseString(vec);
    printVec(vec);
    return 0;
}