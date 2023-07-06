//Given a string array words, return an array of all characters that show up in 
//all strings within the words (including duplicates). You may return the answer 
//in any order. 
//
// 
// Example 1: 
// Input: words = ["bella","label","roller"]
//Output: ["e","l","l"]
// 
// Example 2: 
// Input: words = ["cool","lock","cook"]
//Output: ["c","o"]
// 
// 
// Constraints: 
//
// 
// 1 <= words.length <= 100 
// 1 <= words[i].length <= 100 
// words[i] consists of lowercase English letters. 
// 
//
// Related Topics 数组 哈希表 字符串 👍 338 👎 0


#include "leetcode-base.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> res;
        int hash[26] = {0};
        for(int i = 0; i < words[0].size(); i++) {
            hash[words[0][i] - 'a']++;
        }

        int hash2[26] = {0};
        for(int i = 1; i < words.size(); i++) {
            memset(hash2, 0, 26*sizeof(int));
            for(int j = 0; j < words[i].size(); j++) {
                hash2[words[i][j] - 'a']++;
            }


            for(int j =0; j < 26; j++) {
                hash[j] = min(hash[j], hash2[j]);
            }
        }

        for(int i = 0; i < 26; i++) {
            if(hash[i] != 0) {
                while(hash[i]--) {
                    res.push_back(string(1, 'a' + i));
                }
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    
    return 0;
}