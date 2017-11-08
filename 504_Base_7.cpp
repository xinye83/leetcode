/*
Given an integer, return its base 7 string representation.

Example 1:
Input: 100
Output: "202"

Example 2:
Input: -7
Output: "-10"

Note: The input will be in range of [-1e7, 1e7].
*/

class Solution {
public:
    string convertToBase7(int num) {
        int s = 1;
        
        if (num == 0)
            return "0";
        else if (num < 0) {
            num = -num;
            s = -1;
        }
        
        string ans;
        
        while (num) {
            ans = (char)('0'+num%7) + ans;
            num /= 7;
        }
        
        if (s == -1)
            ans = '-' + ans;
        
        return ans;
    }
};
