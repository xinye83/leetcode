/*
Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a2 + b2 = c.

Example 1:
Input: 5
Output: True
Explanation: 1 * 1 + 2 * 2 = 5

Example 2:
Input: 3
Output: False
*/

bool judgeSquareSum(int c) {
    if (!c || c==1) {
        return 1;
    }
    else if (c%4==3) {
        return 0;
    }
    else if (c%4==0) {
        return judgeSquareSum(c/4);
    }

    int s;
    c--;
    
    for (int i=1; c>0; i++) {
        s=sqrt(c);
        if (s*s==c) {
            return 1;
        }
        i++;
        c -= 4*i;
    }
    
    return !c;
}
