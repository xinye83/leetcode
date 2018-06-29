/*
Given two strings A and B of lowercase letters, return true if and only if we can swap two letters in A so that the result equals B.

Example 1:

Input: A = "ab", B = "ba"
Output: true

Example 2:

Input: A = "ab", B = "ab"
Output: false

Example 3:

Input: A = "aa", B = "aa"
Output: true

Example 4:

Input: A = "aaaaaaabc", B = "aaaaaaacb"
Output: true

Example 5:

Input: A = "", B = "aa"
Output: false
 
Note:

0 <= A.length <= 20000
0 <= B.length <= 20000
A and B consist only of lowercase letters.
*/

class Solution {
public:
    bool buddyStrings(string A, string B) {
        if ( A.size()-B.size() )
            return 0;
        
        int pos[2];
        int c = 0;
        int l[26] = {};
        int flag = 0;
        
        for (int i = 0; i < A.size(); i++) {
            if (c == 2)
                return 0;
            
            l[A[i]-'a']++;
            if (l[A[i]-'a'] > 1)
                flag = 1;
            
            if (A[i] != B[i])
                pos[c++] = i;
        }
        
        if (c == 2 && A[pos[0]] == B[pos[1]] && A[pos[1]] == B[pos[0]])
            return 1;
        
        if (!c && flag)
            return 1;
        
        return 0;
    }
};
