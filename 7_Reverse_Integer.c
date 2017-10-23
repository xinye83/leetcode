// Reverse digits of an integer.
// 
// Example1: x = 123, return 321
// Example2: x = -123, return -321
// 
// click to show spoilers.
// 
// Note:
// The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.

int reverse(int x) {
    int s;
    long y,z;
    
    if (x==0) {
        return 0;
    }
    else if (x>0) {
        s=1;
        y=x;
    }
    else {
        s=-1;
        y=-x;
    }
    
    z=0;
    while (y!=0) {
        z=z*10+y%10;
        y=y/10;
    }
    
    if (z>INT_MAX || z<INT_MIN) {
        return 0;
    }
    else {
        x=z*s;
        return x;
    }
}
