//Given an array of distinct integers nums and a target integer target, return 
//the number of possible combinations that add up to target. 
//
// The test cases are generated so that the answer can fit in a 32-bit integer. 
//
//
// 
// Example 1: 
//
// 
//Input: nums = [1,2,3], target = 4
//Output: 7
//Explanation:
//The possible combination ways are:
//(1, 1, 1, 1)
//(1, 1, 2)
//(1, 2, 1)
//(1, 3)
//(2, 1, 1)
//(2, 2)
//(3, 1)
//Note that different sequences are counted as different combinations.
// 
//
// Example 2: 
//
// 
//Input: nums = [9], target = 3
//Output: 0
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 200 
// 1 <= nums[i] <= 1000 
// All the elements of nums are unique. 
// 1 <= target <= 1000 
// 
//
// 
// Follow up: What if negative numbers are allowed in the given array? How does 
//it change the problem? What limitation we need to add to the question to allow 
//negative numbers? 
//
// Related Topics 数组 动态规划 👍 833 👎 0


#include "leetcode-base.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //完全背包  求排列数
    int combinationSum4II(vector<int>& nums, int target) {
        vector<int> dp(target+1, 0);
        dp[0] = 1;

        for(int j = 0; j <= target; j++) {
            for(int i = 0; i < nums.size(); i++) { //后遍历物品
                //有测试用例超出限制
                if(j >= nums[i] && dp[j-nums[i]] < INT_MAX - dp[j])
                    dp[j] += dp[j-nums[i]];
            }
        }
        //printVec(dp);
        return dp[target];
    }

    int combinationSum4(vector<int>& nums, int target) {

    }

    void backtrack(vector<int>& nums, )

};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    vector<int> nums{10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,370,380,390,400,410,420,430,440,450,460,470,480,490,500,510,520,530,540,550,560,570,580,590,600,610,620,630,640,650,660,670,680,690,700,710,720,730,740,750,760,770,780,790,800,810,820,830,840,850,860,870,880,890,900,910,920,930,940,950,960,970,980,990,111};
    cout << s.combinationSum4(nums, 999) << endl;
    return 0;
}