/*
Given a list of 24-hour clock time points in "Hour:Minutes" format, find the minimum minutes difference between any two time points in the list.

Example 1:
Input: ["23:59","00:00"]
Output: 1

Note:
The number of time points in the given list is at least 2 and won't exceed 20000.
The input time is legal and ranges from 00:00 to 23:59.
*/

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> times(n,0);
        
        for (int i = 0; i < n; ++i) {
            times[i] += (timePoints[i][0]-'0')*600;
            times[i] += (timePoints[i][1]-'0')*60;
            times[i] += (timePoints[i][3]-'0')*10;
            times[i] += timePoints[i][4]-'0';
        }
        
        sort(times.begin(),times.end());
        
        int ans = times[0]+24*60-times[n-1];
        for (int i = 0; i < n-1; ++i)
            ans = min(ans,times[i+1]-times[i]);
        
        return ans;
    }
};
