/*
Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).

Note: You may assume that n is not less than 2 and not larger than 58.
*/

int integerBreak(int n) {
    if (n<4) {
        return n-1;
    }
    
    int ans=1;
    while (n>4) {
        ans*=3;
        n-=3;
    }
    
    return ans*n;
}
