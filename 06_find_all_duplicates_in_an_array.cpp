/*
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]
*/


// Optimization script
#pragma GCC optimize("Ofast")
static auto _ = [] () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
} ();

// Solution begins here
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> twice;
        for (int i : nums) {
            if (nums[abs(i)-1] < 0)
                twice.push_back(abs(i));
            else
                nums[abs(i)-1] = -nums[abs(i)-1];
        }
        return twice;
    }
};