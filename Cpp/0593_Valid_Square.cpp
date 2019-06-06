/*
Given the coordinates of four points in 2D space, return whether the four points could construct a square.

The coordinate (x,y) of a point is represented by an integer array with two integers.

Example:
Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
Output: True
Note:

All the input integers are in the range [-10000, 10000].
A valid square has four equal sides with positive length and four equal angles (90-degree angles).
Input points have no order.
*/

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int> l1 = {p1[0]-p2[0],p1[1]-p2[1]};
        vector<int> l2 = {p3[0]-p4[0],p3[1]-p4[1]};
        
        if ( (l1[0] == 0 && l1[1] == 0) || (l2[0] == 0 && l2[1] == 0)\
            || l1[0]*l1[0]+l1[1]*l1[1] != l2[0]*l2[0]+l2[1]*l2[1])
            return 0;
        
        vector<double> m1 = {(p1[0]+p2[0])*.5,(p1[1]+p2[1])*.5};
        vector<double> m2 = {(p3[0]+p4[0])*.5,(p3[1]+p4[1])*.5};
        
        if (!(l1[0]*l2[0] + l1[1]*l2[1])) {
            if (m1[0] == m2[0] && m1[1] == m2[1])
                return 1;
            else 
                return 0;
        }

        if (!(l1[0]*l2[1] - l1[1]*l2[0])) {
            vector<double> l3 = {m1[0]-m2[0],m1[1]-m2[1]};
            
            if (!(l1[0]*l3[0] + l1[1]*l3[1]) && \
                l1[0]*l1[0]+l1[1]*l1[1] == l3[0]*l3[0]+l3[1]*l3[1])
                return 1;
            else
                return 0;
        }
        
        return 0;
    }
};
