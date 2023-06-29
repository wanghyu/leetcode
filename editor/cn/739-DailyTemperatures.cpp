//Given an array of integers temperatures represents the daily temperatures, 
//return an array answer such that answer[i] is the number of days you have to wait 
//after the iᵗʰ day to get a warmer temperature. If there is no future day for 
//which this is possible, keep answer[i] == 0 instead. 
//
// 
// Example 1: 
// Input: temperatures = [73,74,75,71,69,72,76,73]
//Output: [1,1,4,2,1,1,0,0]
// 
// Example 2: 
// Input: temperatures = [30,40,50,60]
//Output: [1,1,1,0]
// 
// Example 3: 
// Input: temperatures = [30,60,90]
//Output: [1,1,0]
// 
// 
// Constraints: 
//
// 
// 1 <= temperatures.length <= 10⁵ 
// 30 <= temperatures[i] <= 100 
// 
//
// Related Topics 栈 数组 单调栈 👍 1532 👎 0


#include "leetcode-base.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> sk; //单调栈  单调递增 从栈头到栈尾
        vector<int> res(temperatures.size(), 0);

        for(int i = 0; i < temperatures.size(); i++) {
            while(!sk.empty() && temperatures[i] > temperatures[sk.top()]) {
                res[sk.top()] = i - sk.top();
                sk.pop();
            }
            sk.push(i);
        }
        return res;
    }

    //Time Limit
    vector<int> dailyTemperatures2(vector<int>& temperatures) {
        vector<int> res(temperatures.size());
        for(int i = 0; i < temperatures.size(); i++) {
            for(int j = i+1; j < temperatures.size(); j++) {
                if(j == temperatures.size() -1) {
                    res[i] = 0;
                }
                if(temperatures[j] > temperatures[i]) {
                    res[i] = j-i;
                    break;
                }
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    vector<int> tem{73,74,75,71,69,72,76,73};
    auto res = s.dailyTemperatures(tem);
    printVec(res);
    return 0;
}