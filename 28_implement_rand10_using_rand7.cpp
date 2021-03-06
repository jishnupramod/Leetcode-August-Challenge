/*
Given a function rand7 which generates a uniform random integer in the range 1 to 7, write a function rand10 which generates a uniform random integer in the range 1 to 10.

Do NOT use system's Math.random().

 

Example 1:

Input: 1
Output: [7]

Example 2:

Input: 2
Output: [8,4]

Example 3:

Input: 3
Output: [8,1,10]

 

Note:

    rand7 is predefined.
    Each testcase has one argument: n, the number of times that rand10 is called.

 

Follow up:

    What is the expected value for the number of calls to rand7() function?
    Could you minimize the number of calls to rand7()?
*/



// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int generated = rand7();
        while (generated > 5)
            generated = rand7();
        unordered_map<int, pair<int, int>> mp;
        for (int i=1; i<=5; ++i)
            mp[i] = {i, i+5};
        int selector = rand7();
        while (selector == 7)
            selector = rand7();
        return selector % 2 ? mp[generated].first : mp[generated].second;
    }
};


// Concise and efficient
class Solution {
public:
    int rand10() {
        int r, c, idx;
        do {
            r = rand7();
            c = rand7();
            idx = c + (r-1) * 7;
        } while (idx > 40);
        return 1 + (idx-1) % 10;
    }
};


