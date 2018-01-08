/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> index;
        int i = 0;
        int ans = 0;

        for (int j = 0; j < s.size(); ++j) {
            if (index.find(s[j]) != index.end())
                i = max(i,index[s[j]]+1);
            ans = max(ans,j-i+1);
            index[s[j]] = j;
        }
        
        return ans;
    }
};
