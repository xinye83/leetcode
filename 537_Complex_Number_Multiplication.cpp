/*
Given two strings representing two complex numbers.

You need to return a string representing their multiplication. Note i2 = -1 according to the definition.

Example 1:
Input: "1+1i", "1+1i"
Output: "0+2i"
Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.

Example 2:
Input: "1+-1i", "1+-1i"
Output: "0+-2i"
Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.

Note:

The input strings will not have extra blank.
The input strings will be given in the form of a+bi, where the integer a and b will both belong to the range of [-100, 100]. And the output should be also in this form.
*/

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        vector<int> v1 = strtoComplex(a);
        vector<int> v2 = strtoComplex(b);
        
        return to_string(v1[0]*v2[0]-v1[1]*v2[1]) + '+' + to_string(v1[0]*v2[1]+v1[1]*v2[0]) + 'i';
    }
    
    vector<int> strtoComplex(string a) {
        int i = a.find('+');
        
        int x = stoi(a.substr(0,i));
        int y = stoi(a.substr(i+1,a.size()-i-1));
        
        return {x,y};
    }
};
