/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
*/

int uniquePaths(int m, int n) {
    // compute (m+n-2) choose n
    // (m+n-2)!/(m-1)!/(n-1)! = ((m+n-2)*...*m)/((n-1)*...*1)
    
    long ans=1;
    
    if (m<n) {
        int temp=m;
        m=n;
        n=temp;
    }
    
    for (int i=m;i<=n+m-2;i++) {
        ans*=i;
    }
    for (int i=1;i<=n-1;i++) {
        ans/=i;
    }

    return (int)ans;
}
