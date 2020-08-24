/*
Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
*/



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int sum = 0;
    void findSum(TreeNode* root) {
        if (!root) return;
        if (!root->left) {
            findSum(root->right);
            return;
        }
        if (!root->left->left and !root->left->right)
            sum += root->left->val;
        findSum(root->left);
        findSum(root->right);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        findSum(root);
        return sum;
    }
};



// Fancy version with 3 lines
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root, bool left=false) {
        if (!root) return 0;
        if (!root->left and !root->right) return left ? root->val : 0;
        return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
    }
};


