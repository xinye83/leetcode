/*
Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).

Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are all in the range [-10000, 10000] (inclusive).

Example:
Input:
[[0,0],[1,0],[2,0]]

Output:
2

Explanation:
The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
*/

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int n = points.size();
        int c = 0;
        if (n < 3)
            return c;
        
        int d;
        
        for (int i = 0; i < n; ++i) {
            map<int,int> dist;
            map<int,int> :: iterator it;
            
            for (int j = 0; j < n; ++j) {
                d = (points[j].first - points[i].first)*(points[j].first - points[i].first) + \
                    (points[j].second - points[i].second)*(points[j].second - points[i].second);
                
                it = dist.find(d);
                if (it != dist.end())
                    dist[d]++;
                else
                    dist[d] = 1;
            }
            
            for (it = dist.begin(); it != dist.end(); ++it)
                c += it->second * (it->second-1);
        }
        
        return c;
    }
};
