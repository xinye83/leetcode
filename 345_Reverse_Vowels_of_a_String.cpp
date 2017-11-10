/*
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

Note:
The vowels does not include the letter "y".
*/

class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();
        if (n <= 1)
            return s;
        
        vector<int> x = {0,n-1};
        int i = 0;
        
        while (x[0] < x[1]) {
            char temp;
            
            if (s[x[i]] == 'a' || s[x[i]] == 'e' || s[x[i]] == 'i' \
                || s[x[i]] == 'o' || s[x[i]] == 'u' || s[x[i]] == 'A' \
                || s[x[i]] == 'E' || s[x[i]] == 'I' \
                || s[x[i]] == 'O' || s[x[i]] == 'U') {
                if (i == 0) {
                    temp = s[x[i]];
                    i = 1;
                }
                else {
                    s[x[0]] = s[x[1]];
                    s[x[1]] = temp;
                    
                    x[0]++;
                    x[1]--;
                    i = 0;
                }
            }
            else {
                if (i == 0)
                    x[i]++;
                else
                    x[i]--;
            }
        }
        
        return s;
    }
};
