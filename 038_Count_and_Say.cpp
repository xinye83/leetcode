/*
The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

Example 1:

Input: 1
Output: "1"

Example 2:

Input: 4
Output: "1211"
*/

class Solution {
public:
    string countAndSay(int n) {
        string s1 = "";
        
        if (n == 1) 
        {
            s1 += '1';
            return s1;
        }
        
        string s0 = countAndSay(n-1);
        
        int c = 0;    // count
        char s = s0[0]; // current character
        int sz = s0.size();
        int i = 0;
        
        for (i = 0; i <= sz; i++)
        {
            if (s != s0[i] || i == sz)
            {
                s1 += to_string(c)+s;
                
                s = s0[i];
                c = 1;
            }
            else
            {
                ++c;
            }
        }
        
        return s1;
    }
};
