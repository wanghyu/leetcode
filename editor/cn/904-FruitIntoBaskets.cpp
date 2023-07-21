//You are visiting a farm that has a single row of fruit trees arranged from 
//left to right. The trees are represented by an integer array fruits where fruits[i]
// is the type of fruit the iᵗʰ tree produces. 
//
// You want to collect as much fruit as possible. However, the owner has some 
//strict rules that you must follow: 
//
// 
// You only have two baskets, and each basket can only hold a single type of 
//fruit. There is no limit on the amount of fruit each basket can hold. 
// Starting from any tree of your choice, you must pick exactly one fruit from 
//every tree (including the start tree) while moving to the right. The picked 
//fruits must fit in one of your baskets. 
// Once you reach a tree with fruit that cannot fit in your baskets, you must 
//stop. 
// 
//
// Given the integer array fruits, return the maximum number of fruits you can 
//pick. 
//
// 
// Example 1: 
//
// 
//Input: fruits = [1,2,1]
//Output: 3
//Explanation: We can pick from all 3 trees.
// 
//
// Example 2: 
//
// 
//Input: fruits = [0,1,2,2]
//Output: 3
//Explanation: We can pick from trees [1,2,2].
//If we had started at the first tree, we would only pick from trees [0,1].
// 
//
// Example 3: 
//
// 
//Input: fruits = [1,2,3,2,2]
//Output: 4
//Explanation: We can pick from trees [2,3,2,2].
//If we had started at the first tree, we would only pick from trees [1,2].
// 
//
// 
// Constraints: 
//
// 
// 1 <= fruits.length <= 10⁵ 
// 0 <= fruits[i] < fruits.length 
// 
//
// Related Topics 数组 哈希表 滑动窗口 👍 522 👎 0


#include "leetcode-base.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //包含两种元素的最长子序列长度
    int totalFruit(vector<int>& fruits) {
        int left = 0, ans = 0;
        unordered_map<int, int> cnt;

        for(int right = 0; right < fruits.size(); right++) {
            cnt[fruits[right]]++;
            while(cnt.size() > 2) {
                /*
                auto it = cnt.find(fruits[left]);
                it->second--;
                if(it->second == 0) {
                    cnt.erase(it);
                }
                 */
                cnt[fruits[left]]--;
                if(cnt[fruits[left]] == 0) {
                    cnt.erase(fruits[left]);
                }
                left++;
            }
            ans = max(ans, right-left+1);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    vector<int> nums{1,2,3,2,2};
    cout << s.totalFruit(nums) << endl;

    unordered_map<int, int> cnt;
    cnt[1]++;
    cnt.erase(0);
    cout << cnt.size() << endl;

    return 0;
}