//A valid IP address consists of exactly four integers separated by single dots.
// Each integer is between 0 and 255 (inclusive) and cannot have leading zeros. 
//
// 
// For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011
//.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses. 
// 
//
// Given a string s containing only digits, return all possible valid IP 
//addresses that can be formed by inserting dots into s. You are not allowed to reorder 
//or remove any digits in s. You may return the valid IP addresses in any order. 
//
// 
// Example 1: 
//
// 
//Input: s = "25525511135"
//Output: ["255.255.11.135","255.255.111.35"]
// 
//
// Example 2: 
//
// 
//Input: s = "0000"
//Output: ["0.0.0.0"]
// 
//
// Example 3: 
//
// 
//Input: s = "101023"
//Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
// 
//
// 
// Constraints: 
//
// 
// 1 <= s.length <= 20 
// s consists of digits only. 
// 
//
// Related Topics 字符串 回溯 👍 1245 👎 0


#include "leetcode-base.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<string> res;
    string ip;

    bool isValid(const string& s, int start, int end) {
        if(start > end)
            return false;

        if(s[start] == '0' && start != end) {
            return false;
        }

        int num = 0;
        for(int i = start; i <= end; i++) {
            if(s[i] > '9' || s[i] < '0') {
                return false;
            }

            num = num * 10 + (s[i] - '0');
            if(num > 255)
                return false;
        }

        return true;
    }

    //不能重复切割
    void backtrack(string& s, int startIndex, int pointNum) {
        if(pointNum == 3) {
            if(isValid(s, startIndex, s.size()-1)) {
                res.push_back(s);
            }
            return;
        }

        for(int i = startIndex; i < s.size(); i++) {
            if(isValid(s, startIndex, i)) {
                s.insert(s.begin()+i+1, '.');
                pointNum++;
                backtrack(s, i+2, pointNum);
                pointNum--;
                s.erase(s.begin()+i+1);
            } else {
                break;
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        backtrack(s, 0, 0);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    auto res = s.restoreIpAddresses("25525511135");
    printVec(res);

    return 0;
}