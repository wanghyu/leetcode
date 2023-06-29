//Given an array of integers arr, return true if and only if it is a valid 
//mountain array. 
//
// Recall that arr is a mountain array if and only if: 
//
// 
// arr.length >= 3 
// There exists some i with 0 < i < arr.length - 1 such that: 
// 
// arr[0] < arr[1] < ... < arr[i - 1] < arr[i] 
// arr[i] > arr[i + 1] > ... > arr[arr.length - 1] 
// 
// 
// 
// 
// Example 1: 
// Input: arr = [2,1]
//Output: false
// 
// Example 2: 
// Input: arr = [3,5,5]
//Output: false
// 
// Example 3: 
// Input: arr = [0,3,2,1]
//Output: true
// 
// 
// Constraints: 
//
// 
// 1 <= arr.length <= 10⁴ 
// 0 <= arr[i] <= 10⁴ 
// 
//
// Related Topics 数组 👍 212 👎 0


#include "leetcode-base.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() < 3) return false;

        int left = 0, right = arr.size()-1;
        while(left < arr.size() -1  &&  arr[left] < arr[left + 1]) {
            ++left;
        }

        while(right > 0 && arr[right-1] > arr[right]) {
            --right;
        }

        if(left == right && left != 0 && right != arr.size() -1) return true;

        return false;
    }

    bool validMountainArray2(vector<int>& arr) {
        if(arr.size() < 3) return false;

        bool flag = false;
        for(int i = 1; i < arr.size(); i++) {
            if(i != 1 && arr[i] < arr[i-1]) {
                flag = true;
            }

            if(!flag) {
                if(arr[i] <= arr[i-1]) {
                    return false;
                }
            } else {
                if(arr[i] >= arr[i-1]) {
                    return false;
                }
            }
        }
        if(!flag) return false;
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    
    return 0;
}