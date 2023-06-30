//Given an array of intervals intervals where intervals[i] = [starti, endi], 
//return the minimum number of intervals you need to remove to make the rest of the 
//intervals non-overlapping. 
//
// 
// Example 1: 
//
// 
//Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
//Output: 1
//Explanation: [1,3] can be removed and the rest of the intervals are non-
//overlapping.
// 
//
// Example 2: 
//
// 
//Input: intervals = [[1,2],[1,2],[1,2]]
//Output: 2
//Explanation: You need to remove two [1,2] to make the rest of the intervals 
//non-overlapping.
// 
//
// Example 3: 
//
// 
//Input: intervals = [[1,2],[2,3]]
//Output: 0
//Explanation: You don't need to remove any of the intervals since they're 
//already non-overlapping.
// 
//
// 
// Constraints: 
//
// 
// 1 <= intervals.length <= 10⁵ 
// intervals[i].length == 2 
// -5 * 10⁴ <= starti < endi <= 5 * 10⁴ 
// 
//
// Related Topics 贪心 数组 动态规划 排序 👍 994 👎 0


#include "leetcode-base.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    //按照右边界排序
    static bool cmp(vector<int>& a, vector<int>& b) {
          return a[1] < b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end(), cmp);
        int res = 1; //非交叉的区间个数
        int end= intervals[0][1];
        for(int i = 1; i < intervals.size(); i++) {
            if(end <= intervals[i][0]) {
                end = intervals[i][1];
                res++;
            }
        }

        return intervals.size() - res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    
    return 0;
}