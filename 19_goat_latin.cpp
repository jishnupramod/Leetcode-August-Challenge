/*
A sentence S is given, composed of words separated by spaces. Each word consists of lowercase and uppercase letters only.

We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.)

The rules of Goat Latin are as follows:

If a word begins with a vowel (a, e, i, o, or u), append "ma" to the end of the word.
For example, the word 'apple' becomes 'applema'.
 
If a word begins with a consonant (i.e. not a vowel), remove the first letter and append it to the end, then add "ma".
For example, the word "goat" becomes "oatgma".
 
Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
For example, the first word gets "a" added to the end, the second word gets "aa" added to the end and so on.
Return the final sentence representing the conversion from S to Goat Latin. 

 

Example 1:

Input: "I speak Goat Latin"
Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
Example 2:

Input: "The quick brown fox jumped over the lazy dog"
Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
 

Notes:

S contains only uppercase, lowercase and spaces. Exactly one space between each word.
1 <= S.length <= 150.
*/



class Solution {
private:
    void tokenize(vector<string>& words, string s, char delim) {
        stringstream ss(s);
        string str;
        while (getline(ss, str, delim))
            words.push_back(str);
    }
    bool isVowel(char ch) {
        vector<char> vowels = {'a', 'e', 'i','o', 'u'};
        for (char v : vowels)
            if (v == ch or v-32 == ch)
                return true;
        return false;
    }
public:
    string toGoatLatin(string S) {
        vector<string> words;
        tokenize(words, S, ' ');
        string suffix = "a";
        for (string& w : words) {
            if (isVowel(w[0]))
                w += "ma";
            else
                w = w.substr(1) + w.substr(0, 1) + "ma";
            w += suffix;
            suffix += "a";
        }
        string s;
        for (string w : words)
            s = s + w + " ";
        s.pop_back();
        return s;
    }
};
