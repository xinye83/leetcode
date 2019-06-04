/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
*/

class Solution {
public:
    int myAtoi(string str) {
        int n = str.size();
        long c = 0;
        int s = 1;
        int pos = 0;
        int temp;
        
        while (pos < n) {
            if (isspace(str[pos]))
                pos++;
            else
                break;
        }
        
        if (pos == n)
            return 0;
        
        if (str[pos] == '+')
            pos++;
        else if (str[pos] == '-') {
            s = -1;
            pos++;
        }
        
        for ( ; pos < n; pos++) {
            temp = str[pos]-'0';
            if (temp >= 0 && temp < 10) {
                c = c*10 + s*temp;
            }
            else
                break;
            
            if (c > INT_MAX) 
                return INT_MAX;
            else if (c < INT_MIN)
                return INT_MIN;
            
        }
        
        return (int)c;
    }
};
