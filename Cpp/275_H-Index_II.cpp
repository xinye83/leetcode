/*
Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?
*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        
        // if citations[i] >= n-i, then hIndex >= n-i
        if (!n || !citations[n-1])
            return 0;
        if (citations[0] >= n)
            return n;
        
        int x = 0;
        int y = n-1;
        while (y-x > 1) {
            int z = x+(y-x)/2;
            
            if (citations[z] >= n-z)
                y = z;
            else
                x = z;
        }
        
        return n-y;
    }
};
