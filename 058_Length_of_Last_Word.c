/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/

int lengthOfLastWord(char* s) {
    int i=0;
    int l=0;
    int flag=0; // flag=1 if last char is ' '
    
    while (s[i]) {
        if (s[i]==' ') {
            if (flag==0) {
                flag=1;
            }
        }
        else {
            if (flag==0) {
                l++;
            }
            else {
                l=1;
            }
            
            flag=0;
        }
        
        i++;
    }
    
    return l;
}
