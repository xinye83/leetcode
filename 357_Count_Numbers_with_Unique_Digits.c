/*
Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.

Example:
Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99])
*/

int product(int m, int n) {
    // computes m*(m+1)*...*(n-1)*n for 1<=m<n
    int ans=m;
    
    for (int i=m+1;i<=n;i++) {
        ans*=i;
    }
    
    return ans;
}

int countNumbersWithUniqueDigits(int n) {
    if (n==0) {
        return 1;
    }
    else if (n==1) {
        return 10;
    }
    else if (n>10) {
        return countNumbersWithUniqueDigits(10);
    }
    
    return countNumbersWithUniqueDigits(n-1)+product(11-n,10)-product(11-n,9);
}
