/*
Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]
Follow up:

Could you optimize your algorithm to use only O(k) extra space?
*/


// Using O(k^2) space
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> tri(rowIndex+1, vector<int>(rowIndex+1, 0));
        for (int i=0; i<rowIndex+1; ++i)
            tri[i][0] = 1;
        for (int i=1; i<rowIndex+1; ++i) {
            for (int j=1; j<=i; ++j) 
                tri[i][j] = tri[i-1][j-1] + tri[i-1][j];
        }
        vector<int> ans;
        for (int i : tri[rowIndex])
            ans.push_back(i);
        return ans;
    }
};


// O(k) Extra space solution
class Solution {
private: 
    // int fact(int n) {
    //     int f = 1;
    //     for (int i=2; i<=n; ++i)
    //         f *= i;
    //     return f;
    // }
    long long C(unsigned n, int k) {  // Function to find nCr
        if (k > n) return 0;
        if (k * 2 > n) k = n-k;
        if (k == 0) return 1;

        long long result = n;
        for (int i = 2; i <= k; ++i) {
            result *= (n-i+1);
            result /= i;
        }
        return result;
    }
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        for (int i=0; i<=rowIndex; ++i)
            ans.push_back(C(rowIndex, i));
        return ans;
    }
};