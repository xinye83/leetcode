/*
Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.

Please note that the string does not contain any non-printable characters.

Example:

Input: "Hello, my name is John"
Output: 5
*/

class Solution {
public:
    int countSegments(string s) {
        int c = 0;
        int flag = 0;
        
        for (int i = 0; i < s.size(); ++i) {
            if (!flag && s[i] != ' ') {
                flag = 1;
                ++c;
            }
            else if (flag && s[i] == ' ')
                flag = 0;
        }
        
        return c;
    }
};
