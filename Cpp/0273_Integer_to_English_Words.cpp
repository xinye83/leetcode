/*
Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

Example 1:

Input: 123
Output: "One Hundred Twenty Three"

Example 2:

Input: 12345
Output: "Twelve Thousand Three Hundred Forty Five"

Example 3:

Input: 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"

Example 4:

Input: 1234567891
Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"
*/

class Solution {
public:
    const vector<string> magnitude = {""," Thousand"," Million"," Billion"};
    const vector<string> s1 = {"One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten",\
        "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    const vector<string> s2 = {"Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    
    string towords3(int num) {
        // input range: 1 to 999
        string ans;

        if (num >= 100)
            ans += s1[num/100-1] + " Hundred";
        
        int res = num%100;
        if (res) {
            if (num >= 100)
                ans += " ";
            
            if (res <= 19)
                ans += s1[res-1];
            else if (!(res%10))
                ans += s2[res/10-2];
            else
                ans += s2[res/10-2] + " " + s1[res%10-1];
        }
            
        return ans;
    }
    
    string numberToWords(int num) {
        if (!num)
            return "Zero";
        
        string ans;
        int i = 0;
        while (num) {
            if (num%1000) {
                if (!ans.empty())
                    ans = " " + ans;
            
                ans = towords3(num%1000) + magnitude[i] + ans;
            }
            
            i++;
            num /= 1000;
        }
        
        return ans;
    }
};
