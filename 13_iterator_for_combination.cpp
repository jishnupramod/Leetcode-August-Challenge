/*
Design an Iterator class, which has:

A constructor that takes a string characters of sorted distinct lowercase English letters and a number combinationLength as arguments.
A function next() that returns the next combination of length combinationLength in lexicographical order.
A function hasNext() that returns True if and only if there exists a next combination.
 

Example:

CombinationIterator iterator = new CombinationIterator("abc", 2); // creates the iterator.

iterator.next(); // returns "ab"
iterator.hasNext(); // returns true
iterator.next(); // returns "ac"
iterator.hasNext(); // returns true
iterator.next(); // returns "bc"
iterator.hasNext(); // returns false
 

Constraints:

1 <= combinationLength <= characters.length <= 15
There will be at most 10^4 function calls per test.
It's guaranteed that all calls of the function next are valid.
*/



class CombinationIterator {
public:
    vector<string> combinations;
    int iter, size;
    void combUtil(string chars, int n, string s, int index, int i) {
        if (index == n) {
            combinations.push_back(s);
            return;
        }
        if (i >= chars.length())
            return;
        s[index] = chars[i];
        combUtil(chars, n, s, index+1, i+1);
        combUtil(chars, n, s, index, i+1);
    }
    CombinationIterator(string characters, int combinationLength) {
        string comb(combinationLength, ' ');
        iter = 0;
        combUtil(characters, combinationLength, comb, 0, 0);
        size = combinations.size();
    }
    
    string next() {
        return combinations[iter++];
    }
    
    bool hasNext() {
        return iter < size;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */