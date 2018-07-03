/*
There is a special square room with mirrors on each of the four walls.  Except for the southwest corner, there are receptors on each of the remaining corners, numbered 0, 1, and 2.

The square room has walls of length p, and a laser ray from the southwest corner first meets the east wall at a distance q from the 0th receptor.

Return the number of the receptor that the ray meets first.  (It is guaranteed that the ray will meet a receptor eventually.)

Example 1:

Input: p = 2, q = 1
Output: 2
Explanation: The ray meets receptor 2 the first time it gets reflected back to the left wall.

Note:

1 <= p <= 1000
0 <= q <= p
*/

class Solution {
public:
    int gcd(int p, int q) {
        if (p == 1 || q == 1)
            return 1;
        
        if (p == q)
            return p;
        else if (p > q)
            return gcd(p-q,q);
        else
            return gcd(p,q-p);
    }
    
    int lcm(int p, int q) {
        return p*q/gcd(p,q);
    }
    
    int mirrorReflection(int p, int q) {
        int l = lcm(p,q);
        int x = l/q;
        int y = l/p;
        
        return (x+1)%2+y%2;
    }
};
