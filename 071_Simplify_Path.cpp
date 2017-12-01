/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
click to show corner cases.

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
*/

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        
        int i = 0;
        int l = 0;
        while (i < path.size()) {
            if (path[i] == '/') {
                ++i;
            }
            else {
                l = 1;
                while (i+l < path.size()) {
                    if (path[i+l] != '/')
                        ++l;
                    else
                        break;
                }
                
                string temp = path.substr(i,l);
                if (!temp.compare("..")) {
                    if  (!st.empty())
                        st.pop();
                }
                else if (temp.compare("."))
                    st.push(temp);
                
                i += l;
            }
        }
        
        if (st.empty())
            return "/";
        else {
            string ans;
            while (!st.empty()) {
                ans = '/'+st.top()+ans;
                st.pop();
            }
            
            return ans;
        }
        
    }
};
