/*
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. 
A . means it can represent any one letter.

Example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.
*/



class WordDictionary {
    vector<WordDictionary*> children;
    bool isWordEnd;
public:
    /** Initialize your data structure here. */
    WordDictionary() : isWordEnd(false) {
        children = vector<WordDictionary*>(26, nullptr);
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        WordDictionary* curr = this;
        for (char ch : word) {
            if (!curr->children[ch-'a'])
                curr->children[ch-'a'] = new WordDictionary();
            curr = curr->children[ch-'a'];
        }
        curr->isWordEnd = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        WordDictionary* curr = this;
        for (int i=0; i<word.length(); ++i) {
            char ch = word[i];
            if (ch == '.') {
                for (auto c : curr->children)
                    if (c and c->search(word.substr(i+1))) return true;
                return false;
            }
            if (!curr->children[ch-'a']) return false;
            curr = curr->children[ch-'a'];
        }
        return curr and curr->isWordEnd;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */