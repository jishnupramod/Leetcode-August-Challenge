/*
Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

You may return any answer array that satisfies this condition.

 

Example 1:

Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
 

Note:

1 <= A.length <= 5000
0 <= A[i] <= 5000
*/


// O(nlogn) Solution
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        sort(A.begin(), A.end(), [&](int a, int b) {
            return (a%2 < b%2);
        });
        return A;
    }
};


// O(n) Solution and O(n) space
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> res(A.size());
        int i = 0, j = A.size()-1;
        for (int a : A) {
            if (a % 2)
                res[j--] = a;
            else
                res[i++] = a;
        }
        return res;
    }
};


// O(n) Solution with constant space
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int i = 0, j = A.size()-1;
        while (i < j) {
            if (A[i] % 2 > A[j] % 2)
                swap(A[i], A[j]);
            if (A[i] % 2 == 0) ++i;
            if (A[j] % 2 == 1) --j;
        }
        return A;
    }
};


