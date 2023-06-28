//At a lemonade stand, each lemonade costs $5. Customers are standing in a 
//queue to buy from you and order one at a time (in the order specified by bills). 
//Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill.
// You must provide the correct change to each customer so that the net 
//transaction is that the customer pays $5. 
//
// Note that you do not have any change in hand at first. 
//
// Given an integer array bills where bills[i] is the bill the iᵗʰ customer 
//pays, return true if you can provide every customer with the correct change, or 
//false otherwise. 
//
// 
// Example 1: 
//
// 
//Input: bills = [5,5,5,10,20]
//Output: true
//Explanation: 
//From the first 3 customers, we collect three $5 bills in order.
//From the fourth customer, we collect a $10 bill and give back a $5.
//From the fifth customer, we give a $10 bill and a $5 bill.
//Since all customers got correct change, we output true.
// 
//
// Example 2: 
//
// 
//Input: bills = [5,5,10,10,20]
//Output: false
//Explanation: 
//From the first two customers in order, we collect two $5 bills.
//For the next two customers in order, we collect a $10 bill and give back a $5 
//bill.
//For the last customer, we can not give the change of $15 back because we only 
//have two $10 bills.
//Since not every customer received the correct change, the answer is false.
// 
//
// 
// Constraints: 
//
// 
// 1 <= bills.length <= 10⁵ 
// bills[i] is either 5, 10, or 20. 
// 
//
// Related Topics 贪心 数组 👍 462 👎 0


#include "leetcode-base.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> umap;
        umap[5] = 0;
        umap[10] = 0;
        umap[20] = 0;

        for(int i = 0; i < bills.size(); i++) {
            if(bills[i] == 5) {
                umap[5]++;
            } else if(bills[i] == 10) {
                if(umap[5] == 0) {
                    return false;
                }else {
                    umap[5]--;
                    umap[10]++;
                }
            } else {
                if(umap[5] >= 1 && umap[10] >= 1) {
                    umap[10]--;
                    umap[5]--;
                    umap[20]++;
                    continue;
                }

                if(umap[5] >= 3) {
                    umap[5] = umap[5]-3;
                    umap[20]++;
                    continue;
                }

                return false;
            }
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;

    return 0;
}