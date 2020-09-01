/*
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

    Search for a node to remove.
    If the node is found, delete the node.

Note: Time complexity should be O(height of tree).

Example:

root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

Given key to delete is 3. So we find the node with value 3 and delete it.

One valid answer is [5,4,6,2,null,null,7], shown in the following BST.

    5
   / \
  4   6
 /     \
2       7

Another valid answer is [5,2,6,null,4,null,7].

    5
   / \
  2   6
   \   \
    4   7
*/



// Optimization of solution pending...
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
    TreeNode* findNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        if (root->val == key)
            return root;
        if (root->val < key)
            return findNode(root->right, key);
        return findNode(root->left, key);
    }
    
    void deleteLeaf(TreeNode* root, int key, bool afterSwap) {
        if (!root) return;
        if (root->left and root->left->val == key) {
            root->left = nullptr;
            return;
        }
        if (root->right and root->right->val == key) {
            root->right = nullptr;
            return;
        }
        if (!afterSwap) {
            if (root->val < key)
                deleteLeaf(root->right, key, false);
            else
                deleteLeaf(root->left, key, false);
        } else {
            deleteLeaf(root->left, key, true);
            deleteLeaf(root->right, key, true);
        }
    }
    
    void deleteNodeWithSingleChild(TreeNode* root, int key, bool afterSwap) {
        if (!root) return;
        if (root->left and root->left->val == key) {
            if (root->left->left) {
                // cout << "meet here\n";
                root->left = root->left->left;
                return;
            } else if (root->left->right) {
                // cout << "Meet Here\n";
                root->left = root->left->right;
                return;
            }
        } 
        if (root->right and root->right->val == key) {
            if (root->right->left) {
                // cout << "meet here\n";
                root->right = root->right->left;
                return;
            } else if (root->right->right) {
                // cout << "meet here\n";
                root->right = root->right->right;
                return;
            }
        }
        if (!afterSwap) {
            if (root->val < key) 
                deleteNodeWithSingleChild(root->right, key, false);
            else 
                deleteNodeWithSingleChild(root->left, key, false);
        } else {
            deleteNodeWithSingleChild(root->left, key, true);
            deleteNodeWithSingleChild(root->right, key, true);
        }
    }
    
    TreeNode* findInorderSuccessor(TreeNode* node) {
        while (node->left)
            node = node->left;
        return node;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        if (root->val == key and !root->left and !root->right)
            return nullptr;
        if (root->val == key and !root->left) {
            root = root->right;
            return root;
        }
        if (root->val == key and !root->right) {
            root = root->left;
            return root;
        }
        TreeNode* node = findNode(root, key);
        if (!node) return root;
        if (!node->left and !node->right)
            deleteLeaf(root, node->val, false);
        else if (!node->left or !node->right)
            deleteNodeWithSingleChild(root, node->val, false);
        else {
            TreeNode* succ = findInorderSuccessor(node->right);
            // cout << succ->val << "\n";
            int temp = node->val;
            node->val = succ->val;
            succ->val = temp;
            // cout << succ->val << "\n";
            if (!succ->left and !succ->right) {
                // cout << "deleting leaf\n";
                deleteLeaf(root, succ->val, true);
            }
            else if (!succ->left or !succ->right) {
                deleteNodeWithSingleChild(root, succ->val, true);
                // cout << "deleting single child\n";
            }
        }
        return root;
    }
};



// Optimized version
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
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        if (root->val < key)
            root->right = deleteNode(root->right, key);
        else if (root->val > key)
            root->left = deleteNode(root->left, key);
        else {
            if (!root->left and !root->right)
                root = nullptr;
            else if (root->left) {
                TreeNode* pred = root->left;
                while (pred->right)
                    pred = pred->right;
                root->val = pred->val;
                root->left = deleteNode(root->left, pred->val);
            } else if (root->right) {
                TreeNode* succ = root->right;
                while (succ->left)
                    succ = succ->left;
                root->val = succ->val;
                root->right = deleteNode(root->right, succ->val);
            }
        }
        return root;
    }
};
