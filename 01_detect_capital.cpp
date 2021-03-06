/*
Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.
 

Example 1:

Input: "USA"
Output: True
 

Example 2:

Input: "FlaG"
Output: False
 

Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.
*/


class Solution {
private:
    bool check_capital(char ch) {
        if (ch >= 'A' and ch <= 'Z')
            return true;
        return false;
    }
public:
    bool detectCapitalUse(string word) {
        int caps = 0;
        for (char ch : word) 
            if (check_capital(ch))
                ++caps;
        if (caps == word.length() or caps == 0 or caps == 1 and check_capital(word[0]))
            return true;
        return false;
    }
};