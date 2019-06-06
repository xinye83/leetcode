/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/

class Solution {
public:
    bool isAnagram(vector<int> count) {
        for (int i = 0; i < 26; ++i) {
            if (count[i])
                return 0;
        }
        
        return 1;
    }
    
    vector<int> findAnagrams(string s, string p) {
        int m = s.size();
        int n = p.size();
        
        if (m < n)
            return {};
        
        vector<int> count(26,0);
        for (int i = 0; i < n; ++i) {
            ++count[s[i]-'a'];
            --count[p[i]-'a'];
        }
        
        vector<int> ans;
        for (int i = 0; i <= m-n; ++i) {
            if (isAnagram(count))
                ans.push_back(i);
            
            if (i == m-n)
                break;
            
            --count[s[i]-'a'];
            ++count[s[i+n]-'a'];
        }
        
        return ans;
    }
};
