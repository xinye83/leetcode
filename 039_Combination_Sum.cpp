/*
Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7, 
A solution set is: 
[
  [7],
  [2, 2, 3]
]
*/

class Solution {
public:
    struct combination
    {
        vector<int> nums;
        int sum;
    };
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        #include <queue>
        
        vector<vector<int>> ans;
        queue<struct combination> q;
        
        struct combination temp = {{},0};
        int szq = 1;
        q.push(temp);
        
        for (int i = 0; i < candidates.size(); i++)
        {
            for (int j = 1; j <= szq; j++)
            {
                temp = q.front();
                q.pop();
                
                while (temp.sum <= target)
                {
                    if (temp.sum < target)
                    {
                        q.push(temp);
                    }
                    else
                    {
                        ans.push_back(temp.nums);
                        break;
                    }
                    
                    temp.nums.push_back(candidates[i]);
                    temp.sum += candidates[i];
                }
            }
            
            szq = q.size();
        }
        
        return ans;
    }
};
