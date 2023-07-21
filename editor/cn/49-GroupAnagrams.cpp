//Given an array of strings strs, group the anagrams together. You can return 
//the answer in any order. 
//
// An Anagram is a word or phrase formed by rearranging the letters of a 
//different word or phrase, typically using all the original letters exactly once. 
//
// 
// Example 1: 
// Input: strs = ["eat","tea","tan","ate","nat","bat"]
//Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
// 
// Example 2: 
// Input: strs = [""]
//Output: [[""]]
// 
// Example 3: 
// Input: strs = ["a"]
//Output: [["a"]]
// 
// 
// Constraints: 
//
// 
// 1 <= strs.length <= 10⁴ 
// 0 <= strs[i].length <= 100 
// strs[i] consists of lowercase English letters. 
// 
//
// Related Topics 数组 哈希表 字符串 排序 👍 1533 👎 0


#include "leetcode-base.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    bool isAnagram(string s, string t) {
        unordered_map<char, int> uMap;
        for(auto ch: s) {
            uMap[ch]++;
        }
        for(auto ch : t) {
            uMap[ch]--;
        }

        for(auto v : uMap) {
            if(v.second !=0) {
                return false;
            }
        }
        return true;
    }
public:
    //超时了
    vector<vector<string>> groupAnagrams2(vector<string>& strs) {
        sort(strs.begin(), strs.end(), [](string& a, string& b) {
            return a.size() < b.size();
        });

        vector<vector<string>> res;
        int used[10000] = {0};

        for(int i = 0; i < strs.size(); i++) {
            if(used[i] == 0) {
                used[i] = 1;
                vector<string> tmp;
                tmp.push_back(strs[i]);

                for(int j = i+1; j < strs.size(); j++) {
                    if(strs[i].size() != strs[j].size()) {
                        break;
                    }
                    if(isAnagram(strs[i], strs[j])) {
                        used[j] = 1;
                        tmp.push_back(strs[j]);
                    }
                }
                res.push_back(tmp);
            }
        }
        return res;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        vector<string> tmp;
        unordered_map<string, int> uMap;
        int index = 0;

        for(int i = 0; i < strs.size(); i++) {
            auto str = strs[i];
            sort(str.begin(), str.end());

            cout<<"1" << str << " "<< strs[i] <<  endl;
            if(uMap.count(str) == 0) {
                tmp.push_back(strs[i]);
                res.push_back(tmp);
                uMap[str] = index;
                index++;
                tmp.clear();
            } else {
                int idx = uMap[str];
                res[idx].push_back(strs[i]);
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;

    vector<string> strs{"eat","tea","tan","ate","nat","bat"};

    auto res = s.groupAnagrams(strs);
    return 0;
}