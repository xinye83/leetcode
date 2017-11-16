/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else if (st.empty() || (s[i] == ')' && st.top() != '(') \
                     || (s[i] == ']' && st.top() != '[') \
                     || (s[i] == '}' && st.top() != '{') )
                return 0;
            else
                st.pop();
        }
        
        return st.empty();
    }
};
