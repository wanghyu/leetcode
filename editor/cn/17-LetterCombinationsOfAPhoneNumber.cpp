//Given a string containing digits from 2-9 inclusive, return all possible 
//letter combinations that the number could represent. Return the answer in any order. 
//
//
// A mapping of digits to letters (just like on the telephone buttons) is given 
//below. Note that 1 does not map to any letters. 
// 
// 
// Example 1: 
//
// 
//Input: digits = "23"
//Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// 
//
// Example 2: 
//
// 
//Input: digits = ""
//Output: []
// 
//
// Example 3: 
//
// 
//Input: digits = "2"
//Output: ["a","b","c"]
// 
//
// 
// Constraints: 
//
// 
// 0 <= digits.length <= 4 
// digits[i] is a digit in the range ['2', '9']. 
// 
//
// Related Topics 哈希表 字符串 回溯 👍 2500 👎 0


#include "leetcode-base.h"

//数字和字母如何映射？

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    const string letterMap[10] = {
            "", //0
            "", //1
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz",
    };

    vector<string> res;
    string s;

    //index 遍历digits
    void backtrack(string& digits, int index) {
        if(index == digits.size()) {
            res.push_back(s);
            return;
        }

        int digit = digits[index] - '0';
        string letters = letterMap[digit];
        for(int i = 0; i< letters.size(); ++i) {
            s.push_back(letters[i]);
            backtrack(digits, index+1);
            s.pop_back();
        }
    }


public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return vector<string>{};
        backtrack(digits, 0);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    auto res = s.letterCombinations("23");
    printVec(res);
    
    return 0;
}