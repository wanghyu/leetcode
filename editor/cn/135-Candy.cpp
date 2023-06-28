//There are n children standing in a line. Each child is assigned a rating 
//value given in the integer array ratings. 
//
// You are giving candies to these children subjected to the following 
//requirements: 
//
// 
// Each child must have at least one candy. 
// Children with a higher rating get more candies than their neighbors. 
// 
//
// Return the minimum number of candies you need to have to distribute the 
//candies to the children. 
//
// 
// Example 1: 
//
// 
//Input: ratings = [1,0,2]
//Output: 5
//Explanation: You can allocate to the first, second and third child with 2, 1, 
//2 candies respectively.
// 
//
// Example 2: 
//
// 
//Input: ratings = [1,2,2]
//Output: 4
//Explanation: You can allocate to the first, second and third child with 1, 2, 
//1 candies respectively.
//The third child gets 1 candy because it satisfies the above two conditions.
// 
//
// 
// Constraints: 
//
// 
// n == ratings.length 
// 1 <= n <= 2 * 10⁴ 
// 0 <= ratings[i] <= 2 * 10⁴ 
// 
//
// Related Topics 贪心 数组 👍 1222 👎 0


#include "leetcode-base.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int candy(vector<int>& ratings) {

        //先考虑左边，再考虑右边，不要同时考虑
        vector<int> candy(ratings.size(), 1);

        for(int i = 1; i < ratings.size(); i++) {
            if(ratings[i] > ratings[i-1]) {
                candy[i] = candy[i-1] + 1;
            }
        }

        for(int i = ratings.size()-2; i >=0; --i) {
            if(ratings[i] > ratings[i+1]) {
                candy[i] =  candy[i] > candy[i+1] ? candy[i] : candy[i+1] + 1;
            }
        }

        //printVec(candy);
        return accumulate(candy.begin(), candy.end(), 0);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    vector<int> ratings{1,2,2};
    cout << s.candy(ratings) << endl;
    return 0;
}