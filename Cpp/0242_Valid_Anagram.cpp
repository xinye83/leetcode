/*
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return 0;
        
        vector<int> count(26,0);
        for (int i = 0; i < s.size(); ++i) {
            ++count[s[i]-'a'];
            --count[t[i]-'a'];
        }
        
        for (int i = 0; i < 26; ++i) {
            if (count[i])
                return 0;
        }
        
        return 1;
    }
};
