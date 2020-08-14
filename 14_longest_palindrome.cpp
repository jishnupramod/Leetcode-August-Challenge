/*
Given a string which consists of lowercase or uppercase letters, 
find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
*/



class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> letter_cnts;
        bool odd_found = false;
        for (char ch : s)
            ++letter_cnts[ch];
        int len = 0;
        for (auto it=letter_cnts.begin(); it!=letter_cnts.end(); ++it) {
            if (!(it->second % 2)) len += it->second;
            else {
                len += it->second-1;
                odd_found = true;
            }
        }
        return len + odd_found;
    }
};