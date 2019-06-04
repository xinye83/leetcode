/*
Given a sorted integer array without duplicates, return the summary of its ranges.

Example 1:
Input: [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]

Example 2:
Input: [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        
        int x1 = 0;
        int x2;
        
        while (x1 < nums.size()) {
            x2 = x1;
            while (x2 < nums.size()) {
                if (nums[x2+1] - nums[x2] == 1)
                    x2++;
                else
                    break;
            }
                
            if (x1 == x2)
                ans.push_back(to_string(nums[x1]));
            else
                ans.push_back(to_string(nums[x1]) + "->" + to_string(nums[x2]));
            
            x1 = x2+1;
        }

        return ans;
    }
};
