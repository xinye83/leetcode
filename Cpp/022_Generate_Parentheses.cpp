/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

class Solution {
public:
    struct parenthesis
    {
        int c1;
        int c2;
        string s;
    };
    
    vector<string> generateParenthesis(int n) {
        #include <stack>
        
        vector<string> ans;
        stack<struct parenthesis> st;
        st.push({1,0,"("});
        
        while (!st.empty())
        {
            parenthesis a = st.top();
            st.pop();
            
            if (a.c1 == n && a.c2 == n) 
            {
                ans.push_back(a.s);
            }
            
            if (a.c1 < n)
            {
                st.push({a.c1+1,a.c2,a.s+"("});
            }
            
            if (a.c1 > a.c2)
            {
                st.push({a.c1,a.c2+1,a.s+")"});
            }
        }
        
        return ans;
    }
};
