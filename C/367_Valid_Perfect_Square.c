/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Returns: True

Example 2:

Input: 14
Returns: False
*/

bool isPerfectSquare(int num) {
    int res=num%4;
    
    if (res>=2) {
        return 0;
    }
    else if (res==0) {
        return isPerfectSquare(num/4);
    }
    else if (num==1) {
        return 1;
    }
    
    // looking for k(k+1)=(num-1)/4 and k>=1
    num=(num-1)/4;
    
    int k=1;
    int p=2;
    
    while (p<num) {
        p+=2*k+2;
        k++;
    }
    
    return (p==num);
}
