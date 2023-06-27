//You are given an array of integers nums, there is a sliding window of size k 
//which is moving from the very left of the array to the very right. You can only 
//see the k numbers in the window. Each time the sliding window moves right by one 
//position. 
//
// Return the max sliding window. 
//
// 
// Example 1: 
//
// 
//Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
//Output: [3,3,5,5,6,7]
//Explanation: 
//Window position                Max
//---------------               -----
//[1  3  -1] -3  5  3  6  7       3
// 1 [3  -1  -3] 5  3  6  7       3
// 1  3 [-1  -3  5] 3  6  7       5
// 1  3  -1 [-3  5  3] 6  7       5
// 1  3  -1  -3 [5  3  6] 7       6
// 1  3  -1  -3  5 [3  6  7]      7
// 
//
// Example 2: 
//
// 
//Input: nums = [1], k = 1
//Output: [1]
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 10⁵ 
// -10⁴ <= nums[i] <= 10⁴ 
// 1 <= k <= nums.length 
// 
//
// Related Topics 队列 数组 滑动窗口 单调队列 堆（优先队列） 👍 2348 👎 0


#include "leetcode-base.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    class MyQueue { //单调队列 从大到小
    public:
        void push(int x) { //队列里小于x的都要被弹出
            while(!que_.empty() && x > que_.back()) {
                que_.pop_back();
            }
            que_.push_back(x);
        }

        void pop(int x) {
            if(!que_.empty() && x == que_.front()) {
                que_.pop_front();
            }
        }

        int front() const {
            return que_.front();
        }

    private:
        deque<int> que_;
    };

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue que;
        vector<int> result;

        for(int i = 0; i< k; ++i) {
            que.push(nums[i]);
        }
        result.push_back(que.front());

        for(int i = k; i< nums.size(); ++i) {
            que.pop(nums[i-k]);
            que.push(nums[i]);
            result.push_back(que.front());
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    //vector<int> nums = {1,3,-1,-3,5,3,6,7};
    vector<int> nums = {1,-1};
    auto vec = s.maxSlidingWindow(nums, 1);
    printVec(vec);

    return 0;
}