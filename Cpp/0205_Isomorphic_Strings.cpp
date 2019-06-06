/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        if (t.size() != n)
            return 0;
        
        map<int, int> m1;
        map<int, int> m2;
        
        for (int i = 0; i < n; i++) {
            if (m1.find(s[i]) == m1.end() && m2.find(t[i]) == m2.end()) {
                m1.insert(pair<int,int> (s[i],t[i]));
                m2.insert(pair<int,int> (t[i],s[i]));
            }
            else if (m1.find(s[i]) == m1.end() || m2.find(t[i]) == m2.end()) {
                return 0;
            }   
            else if (m1.find(s[i])->second != t[i] || m2.find(t[i])->second != s[i]) {
                return 0;
            }
        }
        
        return 1;
    }
};
