/*
Solve a given equation and return the value of x in the form of string "x=#value". The equation contains only '+', '-' operation, the variable x and its coefficient.

If there is no solution for the equation, return "No solution".

If there are infinite solutions for the equation, return "Infinite solutions".

If there is exactly one solution for the equation, we ensure that the value of x is an integer.

Example 1:
Input: "x+5-3+x=6+x-2"
Output: "x=2"
Example 2:
Input: "x=x"
Output: "Infinite solutions"
Example 3:
Input: "2x=x"
Output: "x=0"
Example 4:
Input: "2x+3x-6x=x+2"
Output: "x=-1"
Example 5:
Input: "x=x+2"
Output: "No solution"
*/

class Solution {
public:
    string solveEquation(string equation) {
        int c1 = 0; // coefficient of x
        int c2 = 0; // constant
        int side = 1;
        
        int i,sign;
        if (equation[0] == '-') {
            i = 1;
            sign = -1;
        }
        else {
            i = 0;
            sign = 1;
        }
        
        while (i < equation.size()) {
            int l = 1;
            
            while (i+l < equation.size() && equation[i+l] != '+' && \
                   equation[i+l] != '-' && equation[i+l] != '=')
                ++l;
            
            if (equation[i+l-1] == 'x') {
                if (l == 1)
                    c1 += side*sign;
                else
                    c1 += side*sign*stoi(equation.substr(i,l-1));
            }
            else {
                c2 += side*sign*stoi(equation.substr(i,l));
            }
            
            if (i+l == equation.size())
                break;
            
            if (equation[i+l] == '+') {
                sign = 1;
                i += l+1;
            }
            else if (equation[i+l] == '-') {
                sign = -1;
                i += l+1;
            }
            else {
                side = -1;
                
                if (equation[i+l+1] == '-') {
                    sign = -1;
                    i += l+2;
                }
                else {
                    sign = 1;
                    i += l+1;
                }
            }
            
        }
        
        if (!c1 && !c2)
            return "Infinite solutions";
        else if (!c1)
            return "No solution";
        else
            return "x="+to_string(-c2/c1);
    }
};
