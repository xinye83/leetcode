/*--------------------------------------
----------------------------------------
The runtime beats 100% of c submissions!
----------------------------------------
--------------------------------------*/

/*
Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.

Example1:

a = 2
b = [3]

Result: 8
Example2:

a = 2
b = [1,0]

Result: 1024
*/

int superPow(int a, int* b, int bSize) {
    int res0 = a%1337;
    int res1 = res0;
    int ans = 1;
    
    for (int i=0;i<bSize;i++) {
        // res0 = res1 = a^(10^i)%1337
        
        if (b[bSize-i-1]>1) {
            for (int j=2;j<=b[bSize-i-1];j++) {
                res1 = (res1*res0)%1337;
            }
        }
        // res1 = a^(10^i*b[bSize-i-1])
        
        if (b[bSize-i-1]>0) {
            ans*=res1;
            ans=ans%1337;
        }

        for (int k=((b[bSize-i-1]>0)?b[bSize-i-1]:1)+1;k<=10;k++) {
            res1 = (res1*res0)%1337;
        }
        // res1 = a^(10^(i+1))
        
        res0 = res1;
    }
    
    return ans;
}
