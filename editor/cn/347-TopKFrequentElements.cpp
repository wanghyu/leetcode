//Given an integer array nums and an integer k, return the k most frequent 
//elements. You may return the answer in any order. 
//
// 
// Example 1: 
// Input: nums = [1,1,1,2,2,3], k = 2
//Output: [1,2]
// 
// Example 2: 
// Input: nums = [1], k = 1
//Output: [1]
// 
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 10⁵ 
// -10⁴ <= nums[i] <= 10⁴ 
// k is in the range [1, the number of unique elements in the array]. 
// It is guaranteed that the answer is unique. 
// 
//
// 
// Follow up: Your algorithm's time complexity must be better than O(n log n), 
//where n is the array's size. 
//
// Related Topics 数组 哈希表 分治 桶排序 计数 快速选择 排序 堆（优先队列） 👍 1585 👎 0


#include "leetcode-base.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //小顶推
    class myComp {
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(auto v : nums) {
            freq[v]++;
        }

        priority_queue<pair<int, int>, vector<pair<int,int>>, myComp> que;
        for(auto it = freq.begin(); it != freq.end(); ++it) {
            que.emplace(*it);
            if(que.size() > k) {
                que.pop();
            }
        }

        vector<int> res;
        for(int i = k-1; i>=0; i--) {
            res.push_back(que.top().first);
            que.pop();
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    vector<int> vec{1,1,1,2,2,3};
    auto res = s.topKFrequent(vec, 2);
    printVec(res);

    return 0;
}