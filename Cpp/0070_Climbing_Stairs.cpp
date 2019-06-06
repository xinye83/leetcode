/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.
*/

class Solution {
public:
    int climbStairs(int n) {
        double x = pow(5,0.5);
        x = (pow((1+x)/2,n+1)-pow((1-x)/2,n+1))/x;
        
        return (int) x;
    }
};
