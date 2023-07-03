//Given an array of integers arr, return true if the number of occurrences of 
//each value in the array is unique or false otherwise. 
//
// 
// Example 1: 
//
// 
//Input: arr = [1,2,2,1,1,3]
//Output: true
//Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two 
//values have the same number of occurrences. 
//
// Example 2: 
//
// 
//Input: arr = [1,2]
//Output: false
// 
//
// Example 3: 
//
// 
//Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
//Output: true
// 
//
// 
// Constraints: 
//
// 
// 1 <= arr.length <= 1000 
// -1000 <= arr[i] <= 1000 
// 
//
// Related Topics 数组 哈希表 👍 184 👎 0


#include "leetcode-base.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int count[2001] = {0};
        for(int i = 0; i<arr.size(); i++) {
            count[arr[i] + 1000]++;
        }

        bool fre[1002] = {false};
        for(int i = 0; i < 2000; i++) {
            if(count[i]) {
                if(fre[count[i]] == false) fre[count[i]] = true;
                else
                    return false;
            }
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    vector<int> arr{-3,0,1,-3,1,1,1,-3,10,0};
    cout << s.uniqueOccurrences(arr) << endl;
    return 0;
}