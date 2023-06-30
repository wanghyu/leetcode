//You are given a string s. We want to partition the string into as many parts 
//as possible so that each letter appears in at most one part. 
//
// Note that the partition is done so that after concatenating all the parts in 
//order, the resultant string should be s. 
//
// Return a list of integers representing the size of these parts. 
//
// 
// Example 1: 
//
// 
//Input: s = "ababcbacadefegdehijhklij"
//Output: [9,7,8]
//Explanation:
//The partition is "ababcbaca", "defegde", "hijhklij".
//This is a partition so that each letter appears in at most one part.
//A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it 
//splits s into less parts.
// 
//
// Example 2: 
//
// 
//Input: s = "eccbbbbdec"
//Output: [10]
// 
//
// 
// Constraints: 
//
// 
// 1 <= s.length <= 500 
// s consists of lowercase English letters. 
// 
//
// Related Topics 贪心 哈希表 双指针 字符串 👍 967 👎 0


#include "leetcode-base.h"

//ababcbacadefegdehijhklij

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> partitionLabels(string s) {
        if(s.size() == 1) return vector<int>{1};

        //记录每个字符最后出现的index
        unordered_map<char, int> uMap;
        for(int i = 0; i< s.size(); i++) {
            uMap[s[i]] = i;
        }

        vector<int> res;
        int start = 0;
        int end = uMap[s[0]];
        for(int i = 0; i < s.size(); i++) {
            if(uMap[s[i]] > end) {
                end = uMap[s[i]];
            }

            if(i == end) {
                res.push_back(i-start + 1);
                start = i + 1;
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    auto res =  s.partitionLabels("eccbbbbdecf");
    printVec(res);
    return 0;
}