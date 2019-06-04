/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        
        if (n1+n2 != n3)
            return 0;
        if (n1 == 0)
            return !s2.compare(s3);
        if (n2 == 0)
            return !s1.compare(s3);
        
        vector<vector<int>> map(n1+1,vector<int>(n2+1,0));  
        for (int i = 0; i <= n1; ++i) {
            for (int j = 0; j <= n2; ++j) {
                if (i == 0 && j == 0)
                    map[i][j] = 1;
                else {
                    if (i != 0 && map[i-1][j])
                        map[i][j] += (s1[i-1] == s3[i+j-1]);
                    if (j != 0 && map[i][j-1])
                        map[i][j] += (s2[j-1] == s3[i+j-1]);
                }
            }
        }
        
        return map[n1][n2];
    }
};
