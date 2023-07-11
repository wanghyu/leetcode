//You are given an array of integers stones where stones[i] is the weight of 
//the iᵗʰ stone. 
//
// We are playing a game with the stones. On each turn, we choose any two 
//stones and smash them together. Suppose the stones have weights x and y with x <= y. 
//The result of this smash is: 
//
// 
// If x == y, both stones are destroyed, and 
// If x != y, the stone of weight x is destroyed, and the stone of weight y has 
//new weight y - x. 
// 
//
// At the end of the game, there is at most one stone left. 
//
// Return the smallest possible weight of the left stone. If there are no 
//stones left, return 0. 
//
// 
// Example 1: 
//
// 
//Input: stones = [2,7,4,1,8,1]
//Output: 1
//Explanation:
//We can combine 2 and 4 to get 2, so the array converts to [2,7,1,8,1] then,
//we can combine 7 and 8 to get 1, so the array converts to [2,1,1,1] then,
//we can combine 2 and 1 to get 1, so the array converts to [1,1,1] then,
//we can combine 1 and 1 to get 0, so the array converts to [1], then that's 
//the optimal value.
// 
//
// Example 2: 
//
// 
//Input: stones = [31,26,33,21,40]
//Output: 5
// 
//
// 
// Constraints: 
//
// 
// 1 <= stones.length <= 30 
// 1 <= stones[i] <= 100 
// 
//
// Related Topics 数组 动态规划 👍 707 👎 0


#include "leetcode-base.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int target = sum / 2 ;
        vector<int> dp(1501, 0);
        for(int i = 0; i < stones.size(); i++) {
            for( int j = target; j >= stones[i]; j--) {
                dp[j] = max(dp[j], dp[j-stones[i]] + stones[i]);
            }
        }

        return  abs(sum - dp[target] * 2);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    vector<int> nums{1,1,4,2,2};
    cout << s.lastStoneWeightII(nums) << endl;
    return 0;
}