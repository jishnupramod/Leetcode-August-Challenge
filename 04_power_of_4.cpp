/*
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example 1:

Input: 16
Output: true
Example 2:

Input: 5
Output: false
Follow up: Could you solve it without loops/recursion?
*/


// Using loop
class Solution {
public:
    bool isPowerOfFour(int num) {
        long long n = 1;
        while (n < num)
            n *= 4;
        return n == num;
    }
};


// Without loops/recursion
class Solution {
public:
    bool isPowerOfFour(int num) {
        double base4 = log(num)/log(4);
        double mod = fmod(base4, 1.0);
        return mod == 0;
    }
};