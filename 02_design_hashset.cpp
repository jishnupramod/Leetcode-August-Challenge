/*
Design a HashSet without using any built-in hash table libraries.

To be specific, your design should include these functions:

add(value): Insert a value into the HashSet. 
contains(value) : Return whether the value exists in the HashSet or not.
remove(value): Remove a value in the HashSet. If the value does not exist in the HashSet, do nothing.

Example:

MyHashSet hashSet = new MyHashSet();
hashSet.add(1);         
hashSet.add(2);         
hashSet.contains(1);    // returns true
hashSet.contains(3);    // returns false (not found)
hashSet.add(2);          
hashSet.contains(2);    // returns true
hashSet.remove(2);          
hashSet.contains(2);    // returns false (already removed)

Note:

All values will be in the range of [0, 1000000].
The number of operations will be in the range of [1, 10000].
Please do not use the built-in HashSet library.
*/


// Using Vector --> High space requirement
class MyHashSet {
public:
    /** Initialize your data structure here. */
    const int max = 1000000;
    vector<bool> hashSet;
    MyHashSet() {
        hashSet.resize(max, 0);
    }
    
    void add(int key) {
        hashSet[key] = true;
    }
    
    void remove(int key) {
        hashSet[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return hashSet[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */


 // Using Chained Hashing --> More Time complex
class MyHashSet {
public:
    /** Initialize your data structure here. */
    const int max = 1000;
    vector<vector<pair<int, bool>>> hash;
    MyHashSet() {
        hash.resize(max);
    }
    
    void add(int key) {
        int index = key % max, i;
        for (i=0; i<hash[index].size(); ++i) {
            if (hash[index][i].first == key) {
                hash[index][i].second = true;
                break;
            }
        }
        if (i == hash[index].size())
            hash[index].push_back(make_pair(key, true));
    }
    
    void remove(int key) {
        int index = key % max;
        for (int i=0; i<hash[index].size(); ++i) {
            if (hash[index][i].first == key) {
                hash[index][i].second = false;
                break;
            }
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int index = key % max;
        bool res = false;
        for (pair<int, bool> p : hash[index]) {
            if (p.first == key) {
                res = p.second;
                break;
            }
        }
        return res;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */