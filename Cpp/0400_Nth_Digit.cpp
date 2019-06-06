/*
Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

Note:
n is positive and will fit within the range of a 32-bit signed integer (n < 231).

Example 1:

Input:
3

Output:
3

Example 2:

Input:
11

Output:
0

Explanation:
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
*/

class Solution {
public:
    int findNthDigit(int n) {
        int i = 1;
        long c = 9;
        
        while (n > c) {
            n -= c;
            c /= i++;
            c *= i*10;
        }
        
        int r = i - --n%i;
        n /= i;
        long a = n + pow(10,i-1);
        
        // the r-th digit from the right in number n
        while (r != 1) {
            a /= 10;
            r--;
        }
        
        return a%10;
    }
};
