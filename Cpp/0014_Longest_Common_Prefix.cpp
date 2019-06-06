/*
Write a function to find the longest common prefix string amongst an array of strings.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        
        if (!n)
            return "";
        else if (n == 1)
            return strs[0];
        
        string prefix;

        for (int i = 0; i < strs[0].size(); i++) {
            for (int j = 1; j < n; j++) {
                if (strs[0][i] != strs[j][i])
                    return prefix;
            }
            
            prefix += strs[0][i];
        }
        
        return prefix;
    }
};
