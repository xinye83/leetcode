/*
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number, and n does not exceed 1690.
*/

int min(int a, int b, int c) {
    if (a<=b && a<=c) {
        return a;
    }
    else if (b<=a && b<=c) {
        return b;
    }
    else {
        return c;
    }
}

int nthUglyNumber(int n) {
    if (n==1) {
        return 1;
    }
    
    int* uglynum= (int*) malloc(n*sizeof(int));
    int index[3]={0,0,0};
    
    uglynum[0]=1;
    
    for (int j=1;j<n;j++) {
        uglynum[j]=min(2*uglynum[index[0]],3*uglynum[index[1]],5*uglynum[index[2]]);
        
        if (j==n-1) {
            break;
        }
        
        if (2*uglynum[index[0]]==uglynum[j]) {
            index[0]++;
        }
        if (3*uglynum[index[1]]==uglynum[j]) {
            index[1]++;
        }
        if (5*uglynum[index[2]]==uglynum[j]) {
            index[2]++;
        }
    }
    
    return uglynum[n-1];
}
