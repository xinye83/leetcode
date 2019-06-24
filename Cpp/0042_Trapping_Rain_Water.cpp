/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
*/

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2)
            return 0;
        
        vector<int> left, right;
        
        for (int i = 0; i < height.size(); ++i) {
            if (left.size() == 0 && height[i] > 0)
                left.push_back(i);
            else if (left.size() > 0 && height[i] > height[left[left.size()-1]])
                left.push_back(i);
        }
        
        if (left.size() == 0)
            return 0;
        
        for (int i = height.size()-1; i >= left[left.size()-1]; --i) {
            if (right.size() == 0 && height[i] > 0)
                right.push_back(i);
            else if (right.size() > 0 && height[i] >= height[right[right.size()-1]])
                right.push_back(i);
        }
        
        int ans = 0;
        for (int i = left.size()-1; i > 0; --i) {
            for (int j = left[i-1]+1; j < left[i]; ++j)
                ans += height[left[i-1]]-height[j];
        }
        
        for (int i = right.size()-1; i > 0; --i) {
            for (int j = right[i]+1; j < right[i-1]; ++j)
                ans += height[right[i-1]]-height[j];
        }
        
        return ans;
    }
};
