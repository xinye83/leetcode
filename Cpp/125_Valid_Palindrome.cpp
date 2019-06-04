/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int pos[2] = {0,s.size()-1};
        int flag = 0;
        int b;
        
        while (pos[0] < pos[1]) {
            b = (isdigit(s[pos[flag]]) || isalpha(s[pos[flag]]));
            if (isupper(s[pos[flag]]))
                s[pos[flag]] += 32;
            
            if (flag == 0) {
                if (!b)
                    ++pos[0];
                else
                    flag = 1;
            }
            else {
                if (!b)
                    --pos[1];
                else if (s[pos[0]] != s[pos[1]])
                    return 0;
                else {
                    ++pos[0];
                    --pos[1];
                    flag = 0;
                }
            }
        }
        
        return 1;
    }
};
