/*
Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".

Example 1:
Input: [5, 4, 3, 2, 1]
Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal". 
For the left two athletes, you just need to output their relative ranks according to their scores.

Note:
N is a positive integer and won't exceed 10,000.
All the scores of athletes are guaranteed to be unique.
*/

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<pair<int,int>> scores(nums.size());
        
        for (int i = 0; i < nums.size(); ++i) {
            scores[i].first = nums[i];
            scores[i].second = i;
        }
        
        sort(scores.begin(),scores.end());
        
        vector<string> ans(nums.size());
        
        for (int i = 1; i <= nums.size(); ++i) {
            if (i <= 3) {
                if (i == 1)
                    ans[scores[nums.size()-i].second] = "Gold";
                else if (i == 2)
                    ans[scores[nums.size()-i].second] = "Silver";
                else
                    ans[scores[nums.size()-i].second] = "Bronze";
                
                ans[scores[nums.size()-i].second] += " Medal";
            }
            else
                ans[scores[nums.size()-i].second] = to_string(i);
        }
        
        return ans;
    }
};
