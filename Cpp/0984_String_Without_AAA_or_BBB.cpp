/*
Given two integers A and B, return any string S such that:

S has length A + B and contains exactly A 'a' letters, and exactly B 'b' letters;
The substring 'aaa' does not occur in S;
The substring 'bbb' does not occur in S.
 

Example 1:

Input: A = 1, B = 2
Output: "abb"
Explanation: "abb", "bab" and "bba" are all correct answers.

Example 2:

Input: A = 4, B = 1
Output: "aabaa"
 

Note:

0 <= A <= 100
0 <= B <= 100
It is guaranteed such an S exists for the given A and B.
*/

class Solution {
public:
    string strWithout3a3b(int A, int B) {
        return strWithout3a3b(A, B, (A >= B));
    }
    
    string strWithout3a3b(int A, int B, int flag) {
        string ans;
        
        if (A == 0) {
            for (int i = 0; i < B; ++i)
                ans += "b";
            
            return ans;
        }
        if (B == 0) {
            for (int i = 0; i < A; ++i)
                ans += "a";
            
            return ans;
        }
        
        if (A == B) {
            if (flag == 1) {
                ans = "a"+strWithout3a3b(A-1, B, 1-flag);
            }
            else {
                ans = "b"+strWithout3a3b(A, B-1, 1-flag);
            }
        }
        else if (A > B) {
            if (flag == 1) {
                ans = "aa"+strWithout3a3b(A-2, B, 1-flag);
            }
            else {
                ans = "b"+strWithout3a3b(A, B-1, 1-flag);
            }
        }
        else {
            if (flag == 1) {
                ans = "a"+strWithout3a3b(A-1, B, 1-flag);
            }
            else {
                ans = "bb"+strWithout3a3b(A, B-2, 1-flag);
            }
        }
        
        return ans;
    }
};
