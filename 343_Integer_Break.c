/*
Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).

Note: You may assume that n is not less than 2 and not larger than 58.
*/

int integerBreak(int n) {
    if (n==2) {
        return 1;
    }
    else if (n==3) {
        return 2;
    }
    
    int a=n/3;
    int b=n%3;
    
    if (b==0) {
        return pow(3,a);
    }
    else if (b==1) {
        return pow(3,a-1)*4;
    }
    else {
        return pow(3,a)*2;
    }
}
