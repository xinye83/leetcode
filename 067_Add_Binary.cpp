/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size();
        int n = b.size();
        
        if (!m)
            return b;
        if (!n)
            return a;
        
        if (m < n) {
            swap(a,b);
            swap(m,n);
        }
            
        int num;
        int flag = 0;
        for (int i = 1; i <= n; ++i) {
            num = a[m-i]-'0'+b[n-i]-'0'+flag;
            
            if (num >= 2) {
                a[m-i] = num-2+'0';
                flag = 1;
            }
            else {
                a[m-i] = num+'0';
                flag = 0;
            }
        }
        
        // a[m-n-1] to a[0]
        int i = m-n-1;
        while (flag) {
            if (i >= 0) {
                if (a[i]-'0')
                    a[i] = '0';
                else {
                    a[i]++;
                    flag = 0;
                }
            }
            else {
                a = '1'+a;
                break;
            }
                
            --i;
        }
        
        return a;
    }
};
