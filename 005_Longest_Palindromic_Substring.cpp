/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.

Example:

Input: "cbbd"

Output: "bb"
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int len = 1;
        int a = 0;
        int n = s.size();
        
        for (int i = 0; i < 2*n; ++i) {
            int x = i/2;
            int y = i-x;
            
            if (s[x] != s[y])
                continue;
            
            if (2*min(x+1,n-y)-(x==y) < len)
                continue;
            
            while (x-1 >= 0 && y+1 < n && s[x-1] == s[y+1]) {
                x--;
                y++;
            }
            
            if (len < y-x+1) {
                len = y-x+1;
                a = x;
            }
        }
        
        return s.substr(a,len);
    }
};
