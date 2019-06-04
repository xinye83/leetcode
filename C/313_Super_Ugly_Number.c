/*
Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.

Note:
(1) 1 is a super ugly number for any given primes.
(2) The given numbers in primes are in ascending order.
(3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
(4) The nth super ugly number is guaranteed to fit in a 32-bit signed integer.
*/

int min(int* values, int valuesSize) {
    int min=values[0];
    
    if (valuesSize==1) {
        return min;
    }
    
    for (int i=1;i<valuesSize;i++) {
        if (values[i]<min) {
            min=values[i];
        }
    }
    
    return min;
}

int nthSuperUglyNumber(int n, int* primes, int primesSize) {
    if (n==1) {
        return 1;
    }
    
    int* superuglynum = (int*) malloc(n*sizeof(int));
    int* index = (int*) malloc(primesSize*sizeof(int));
    int* values = (int*) malloc(primesSize*sizeof(int));
    
    superuglynum[0]=1;
    
    for (int i=1;i<n;i++) {
        
        for (int j=0;j<primesSize;j++) {
            if (i==1) {
                index[j]=0;
            }
            values[j]=primes[j]*superuglynum[index[j]];
        }
        
        superuglynum[i]=min(values,primesSize);
        
        if (i==n-1) {
            break;
        }
        
        for (int j=0;j<primesSize;j++) {
            if (superuglynum[i]==values[j]) {
                index[j]++;
            }
        }
    }
    
    return superuglynum[n-1];
}
