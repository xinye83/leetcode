/*
Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.

Example:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"

Restrictions:
The string consists of lower English letters only.
Length of the given string and k will in the range [1, 10000]
*/

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        int i = 0;
        
        while (n > 0) {
            // reverse i to i+min(k,n)-1
            int c = min(k,n)-1;
            int j = 0;
            while (2*j < c) {
                swap(s[i+j],s[i+c-j]);
                ++j;
            }
            
            n -= 2*k;
            i += 2*k;
        }
        
        return s;
    }
};
