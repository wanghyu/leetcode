//Given two strings s and t of lengths m and n respectively, return the minimum 
//window substring of s such that every character in t (including duplicates) is 
//included in the window. If there is no such substring, return the empty string 
//"". 
//
// The testcases will be generated such that the answer is unique. 
//
// 
// Example 1: 
//
// 
//Input: s = "ADOBECODEBANC", t = "ABC"
//Output: "BANC"
//Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' 
//from string t.
// 
//
// Example 2: 
//
// 
//Input: s = "a", t = "a"
//Output: "a"
//Explanation: The entire string s is the minimum window.
// 
//
// Example 3: 
//
// 
//Input: s = "a", t = "aa"
//Output: ""
//Explanation: Both 'a's from t must be included in the window.
//Since the largest window of s only has one 'a', return empty string.
// 
//
// 
// Constraints: 
//
// 
// m == s.length 
// n == t.length 
// 1 <= m, n <= 10⁵ 
// s and t consist of uppercase and lowercase English letters. 
// 
//
// 
// Follow up: Could you find an algorithm that runs in O(m + n) time? 
//
// Related Topics 哈希表 字符串 滑动窗口 👍 2570 👎 0


#include "leetcode-base.h"



//leetcode submit region begin(Prohibit modification and deletion)
/*class Solution {
private:
*//*    bool contain(string str, string t) {
        for(int i = 0; i < t.size(); i++) {
            if(str.find(t[i]) == string::npos) {
                return false;
            }
        }
        return true;
    }*//*

    bool contain(unordered_map<char, int>& sMap, unordered_map<char, int>& tMap) {
        for(auto it = tMap.begin(); it != tMap.end(); it++) {
            auto it2 = sMap.find(it->first);
            if(it2 == sMap.end() || it2->second < it->second) {
                return false;
            }
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";

        unordered_map<char, int> tMap;
        for(int i = 0; i < t.size(); i++) {
            tMap[t[i]]++;
        }

        int left = 0;
        int min_l = 0, min_len = s.size()+1;

        unordered_map<char, int> sMap;
        for(int right = 0; right < s.size(); right++) {
            sMap[s[right]]++;
            while(contain(sMap, tMap) && left <= right) {
                if(right - left + 1 < min_len) {
                    min_len = right - left + 1;
                    min_l = left;
                }

                sMap[s[left]]--;
                left++;
            }
        }
        return min_len > s.size() ? string() : s.substr(min_l, min_len);
    }
};*/
class Solution {
    bool contain(unordered_map<char,int>& sMap, unordered_map<char,int> tMap) {
        for(auto it = tMap.begin(); it != tMap.end(); it++) {
            auto it2 = sMap.find(it->first);
            if(it2 == sMap.end()) {
                return false;
            }
            if(it2->second < it->second) {
                return false;
            }
        }
        return true;
    }

public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";

        unordered_map<char, int> tMap;
        for(auto ch : t) {
            tMap[ch]++;
        }

        int i = 0;
        int min_l;
        int min_len = INT32_MAX;
        unordered_map<char, int> sMap;
        for(int j = 0; j< s.size(); j++) {
            sMap[s[j]]++;
            while(contain(sMap, tMap) && i <= j) {
                if(min_len > j - i + 1) {
                    min_len = j - i + 1;
                    min_l = i;
                }
                sMap[s[i]]--;
                i++;
            }
        }
        return min_len == INT32_MAX? string("") : s.substr(min_l, min_len);
    }
};

//leetcode submit region end(Prohibit modification and deletion)


int main(){
    [[maybe_unused]] Solution s;
    cout << s.minWindow("A", "A") << endl;

    return 0;
}