//Write an algorithm to determine if a number n is happy. 
//
// A happy number is a number defined by the following process: 
//
// 
// Starting with any positive integer, replace the number by the sum of the 
//squares of its digits. 
// Repeat the process until the number equals 1 (where it will stay), or it 
//loops endlessly in a cycle which does not include 1. 
// Those numbers for which this process ends in 1 are happy. 
// 
//
// Return true if n is a happy number, and false if not. 
//
// 
// Example 1: 
//
// 
//Input: n = 19
//Output: true
//Explanation:
//1² + 9² = 82
//8² + 2² = 68
//6² + 8² = 100
//1² + 0² + 0² = 1
// 
//
// Example 2: 
//
// 
//Input: n = 2
//Output: false
// 
//
// 
// Constraints: 
//
// 
// 1 <= n <= 2³¹ - 1 
// 
//
// Related Topics 哈希表 数学 双指针 👍 1345 👎 0


#include "leetcode-base.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    int sumSquares(int n) {
        string str = to_string(n);
        int sum = 0;
        int tmp;
        for(int i = 0; i < str.size(); i++) {
            tmp = str[i] - '0';
            cout << "tmp:" << tmp << endl;
            sum += tmp * tmp;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> uSet;
        int sum;
        while(true) {
            sum = sumSquares(n);
            if(sum == 1) return true;
            if(uSet.find(sum) != uSet.end()) {
                return false;
            }
            uSet.insert(sum);
            n = sum;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    
    return 0;
}