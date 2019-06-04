/*
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note: All inputs will be in lower-case.
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> group;
        
        for (int i = 0; i < strs.size(); ++i) {
            string s = strs[i];
            sort(s.begin(),s.end());
            
            group[s].push_back(strs[i]);
        }
        
        vector<vector<string>> ans;
        for (auto it = group.begin(); it != group.end(); ++it)
            ans.push_back(it->second);
        
        return ans;
    }
};
