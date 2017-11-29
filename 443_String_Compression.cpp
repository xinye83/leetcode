/*
Given an array of characters, compress it in-place.

The length after compression must always be smaller than or equal to the original array.

Every element of the array should be a character (not int) of length 1.

After you are done modifying the input array in-place, return the new length of the array.


Follow up:
Could you solve it using only O(1) extra space?

Example 1:
Input:
["a","a","b","b","c","c","c"]

Output:
Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]

Explanation:
"aa" is replaced by "a2". "bb" is replaced by "b2". "ccc" is replaced by "c3".

Example 2:
Input:
["a"]

Output:
Return 1, and the first 1 characters of the input array should be: ["a"]

Explanation:
Nothing is replaced.

Example 3:
Input:
["a","b","b","b","b","b","b","b","b","b","b","b","b"]

Output:
Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].

Explanation:
Since the character "a" does not repeat, it is not compressed. "bbbbbbbbbbbb" is replaced by "b12".
Notice each digit has it's own entry in the array.

Note:
All characters have an ASCII value in [35, 126].
1 <= len(chars) <= 1000.
*/

class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int j = 0;
        
        while (i < chars.size()) {
            while (j+1 < chars.size() && chars[j+1] == chars[i])
                ++j;
            
            if (i==j) {
                ++i;
                ++j;
            }
            else {
                int len = j-i+1;
                int l = 0;

                while (len) {
                    chars[j-l] = '0'+len%10;
                    len /= 10;
                    ++l;
                }

                if (i+1 <= j-l)
                    chars.erase(chars.begin()+i+1,chars.begin()+j-l+1);

                i += l+1;
                j = i;
            }
        }
        
        return chars.size();
    }
};
