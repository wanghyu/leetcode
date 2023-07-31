//Given a positive integer n, generate an n x n matrix filled with elements 
//from 1 to n² in spiral order. 
//
// 
// Example 1: 
// 
// 
//Input: n = 3
//Output: [[1,2,3],[8,9,4],[7,6,5]]
// 
//
// Example 2: 
//
// 
//Input: n = 1
//Output: [[1]]
// 
//
// 
// Constraints: 
//
// 
// 1 <= n <= 20 
// 
//
// Related Topics 数组 矩阵 模拟 👍 1092 👎 0


#include "leetcode-base.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> arr(n, vector<int>(n, 0));
        int i = 0, j = 0;
        int k = 1;
        int startx = 0, starty = 0;

        int loop = n/2;
        int offset = 1;

        while(loop>0) {
            i = startx;
            j = starty;

            for (j = starty; j < n - offset; j++) {
                arr[i][j] = k++;
            }

            for (i = startx; i < n - offset; i++) {
                arr[i][j] = k++;
            }

            for (; j > starty; j--) {
                arr[i][j] = k++;
            }

            for (; i > startx; i--) {
                arr[i][j] = k++;
            }

            startx++;
            starty++;
            loop--;
            offset++;
        }

        if(n % 2) {
            arr[n/2][n/2] = k;
        }
        //printVecVec(arr);

        return arr;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    s.generateMatrix(4);
    return 0;
}