/*
Given a string representing an expression of fraction addition and subtraction, you need to return the calculation result in string format. The final result should be irreducible fraction. If your final result is an integer, say 2, you need to change it to the format of fraction that has denominator 1. So in this case, 2 should be converted to 2/1.

Example 1:
Input:"-1/2+1/2"
Output: "0/1"

Example 2:
Input:"-1/2+1/2+1/3"
Output: "1/3"

Example 3:
Input:"1/3-1/2"
Output: "-1/6"

Example 4:
Input:"5/3+1/3"
Output: "2/1"

Note:
The input string only contains '0' to '9', '/', '+' and '-'. So does the output.
Each fraction (input and output) has format ±numerator/denominator. If the first input fraction or the output is positive, then '+' will be omitted.
The input only contains valid irreducible fractions, where the numerator and denominator of each fraction will always be in the range [1,10]. If the denominator is 1, it means this fraction is actually an integer in a fraction format defined above.
The number of given fractions will be in the range [1,10].
The numerator and denominator of the final result are guaranteed to be valid and in the range of 32-bit int.
*/

class Solution {
public:
    int gcd(int a, int b) {
        if (a==b)
            return a;
        if (a == 1 || b == 1)
            return 1;
        
        return (a > b) ? gcd(a-b,b) : gcd(a,b-a);
    }
    
    vector<int> addTwoFraction(vector<int> current, vector<int> next) {
        int n1 = current[0];
        int d1 = current[1];
        int n2 = next[0];
        int d2 = next[1];
        
        n1 = n1*d2+n2*d1;
        d1 *=d2;

        if (!n1)
            d1 = 1;
        else {
            int g = gcd(abs(n1),d1);
            n1 /= g;
            d1 /= g;
        }
        
        return {n1,d1};
    }
    
    string fractionAddition(string expression) {
        int i=0;
        int j,k;
        
        vector<int> sum(2,0);
        sum[1] = 1;
        
        while (i < expression.size()) {
            j = i+1;
            while (expression[j] != '/')
                ++j;
            
            k = j+1;
            while (k <= expression.size() && expression[k] != '+' && expression[k] != '-')
                ++k;
            
            // numerator   i ~ j-1
            // denominator j+1 ~ k-1
            sum = addTwoFraction(sum,{stoi(expression.substr(i,j-i)),stoi(expression.substr(j+1,k-j-1))});
            
            i = k;
        }
        
        return to_string(sum[0])+"/"+to_string(sum[1]);
    }
};
