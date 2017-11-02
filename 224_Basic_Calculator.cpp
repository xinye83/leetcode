/*
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23

Note: Do not use the eval built-in library function.
*/

class Solution {
public:
    int calculate(string s) {
        int ans = 0;
        int flag = 1; // flag for + or -
        int i = 0;
        
        while (i < s.size()) {
            if (isspace(s[i]))
                i++;
            else {
                if (s[i] == '+') {
                    flag = 1;
                    i++;
                }
                else if (s[i] == '-') {
                    flag = -1;
                    i++;
                }
                else if (isdigit(s[i])) {
                    int l = 1;
                    while (isdigit(s[i+l]))
                        l++;
                    
                    ans += flag*stoi(s.substr(i,l));
                    
                    i += l;
                }
                else if (s[i] == '(') {
                    int c = 1;
                    int l = 0;
                    while (c) {
                        if (s[i+1+l] == '(') {
                            c++;
                        }
                        else if (s[i+1+l] == ')') {
                            c--;
                        }
                        l++;
                    }
                    
                    ans += flag*calculate(s.substr(i+1,l-1));
                    i += l+1;
                }
            }
        }
        
        return ans;
    }
};
