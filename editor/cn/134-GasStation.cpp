//There are n gas stations along a circular route, where the amount of gas at 
//the iᵗʰ station is gas[i]. 
//
// You have a car with an unlimited gas tank and it costs cost[i] of gas to 
//travel from the iᵗʰ station to its next (i + 1)ᵗʰ station. You begin the journey 
//with an empty tank at one of the gas stations. 
//
// Given two integer arrays gas and cost, return the starting gas station's 
//index if you can travel around the circuit once in the clockwise direction, 
//otherwise return -1. If there exists a solution, it is guaranteed to be unique 
//
// 
// Example 1: 
//
// 
//Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
//Output: 3
//Explanation:
//Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4
// = 4
//Travel to station 4. Your tank = 4 - 1 + 5 = 8
//Travel to station 0. Your tank = 8 - 2 + 1 = 7
//Travel to station 1. Your tank = 7 - 3 + 2 = 6
//Travel to station 2. Your tank = 6 - 4 + 3 = 5
//Travel to station 3. The cost is 5. Your gas is just enough to travel back to 
//station 3.
//Therefore, return 3 as the starting index.
// 
//
// Example 2: 
//
// 
//Input: gas = [2,3,4], cost = [3,4,3]
//Output: -1
//Explanation:
//You can't start at station 0 or 1, as there is not enough gas to travel to 
//the next station.
//Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
//
//Travel to station 0. Your tank = 4 - 3 + 2 = 3
//Travel to station 1. Your tank = 3 - 3 + 3 = 3
//You cannot travel back to station 2, as it requires 4 unit of gas but you 
//only have 3.
//Therefore, you can't travel around the circuit once no matter where you start.
//
// 
//
// 
// Constraints: 
//
// 
// n == gas.length == cost.length 
// 1 <= n <= 10⁵ 
// 0 <= gas[i], cost[i] <= 10⁴ 
// 
//
// Related Topics 贪心 数组 👍 1285 👎 0


#include "leetcode-base.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
//    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//        //暴力 超时了
//        for(int i = 0; i < cost.size(); i++) {
//            int rest = gas[i] - cost[i];
//            int index = (i + 1) % cost.size() ;
//            while(rest > 0 && index != i) {
//                rest += gas[index] - cost[index];
//                index = (index + 1) % cost.size();
//            }
//            if(rest >= 0 && index == i) return i;
//        }
//        return -1;
//    }


    /*
     * 情况1： 如果gas的总和小于cost的总和，都跑不了一圈
     * 情况2： 如果rest[i] = gas[i]- cost[i]为跑完一个station剩下的油量， 如果从0开始，到最后一站，如果累加的过程中没有出现
     *          负值，则油量都是足够的，直接返回0
     * 情况3：
     */
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        int min = INT32_MAX;
        for(int i = 0; i < gas.size(); i++) {
            sum += gas[i] - cost[i];
            if(sum < min) {
                min = sum;
            }
        }

        if(sum < 0) return -1; //情况1
        if(min >=0) return 0;  //情况2

        //从后像前
        for(int i = gas.size()-1; i >=0; --i) {
            int rest = gas[i] - cost[i];
            min += rest;
            if(min >= 0) {
                return i;
            }
        }
        return -1;
    }

};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    vector<int> gas{1,2,3,4,5};
    vector<int> cost{3,4,5,1,2};

    cout << s.canCompleteCircuit(gas, cost) << endl;
    return 0;
}