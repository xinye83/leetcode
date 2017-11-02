/*
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".
*/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (!numerator)
            return "0";
        
        string ans;
        if ((numerator > 0 && denominator < 0) || (numerator < 0 && denominator > 0))
            ans = '-';

        long numerator1 = abs((long)numerator);
        long denominator1 = abs((long)denominator);
        ans += to_string((long)numerator1/(long)denominator1);
        
        long r = numerator1%denominator1;
        
        if (!r)
            return ans;
        
        ans += '.';
        
        vector<vector<long>> a;
        long q0;
        long r0;
        int flag = -1;
        while (r) {
            r *= 10;
            q0 = r/denominator1;
            r0 = r%denominator1;
            
            for (int i = 0; i < a.size(); i++) {
                if (q0 == a[i][0] && r0 == a[i][1]) {
                    flag = i;
                    break;
                }
            }
            
            if (flag >= 0) {
                ans.insert(ans.size()-a.size()+flag, "(");
                ans += ')';
                break;
            }
            
            ans += ('0'+(int)q0);
            a.push_back({q0,r0});
            
            r = r0;
        }
        
        return ans;
    }
};
