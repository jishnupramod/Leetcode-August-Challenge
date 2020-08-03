/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
 

Constraints:

s consists only of printable ASCII characters.
*/


class Solution {
public:
    bool isPalindrome(string s) {
        string alphanum = "";
        for (char ch : s) {
            if (isalpha(ch))
                alphanum += tolower(ch);
            else if (ch >= '0' and ch <= '9')
                alphanum += ch;
        }
        int n = alphanum.length();
        for (int i=0; i<n/2; ++i) {
            if (alphanum[i] != alphanum[n-i-1])
                return false;
        }
        return true;
    }
};