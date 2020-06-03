/*
Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1
*/


class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // The following is basically equivalent to:
        // if (!root) return root;
        // TreeNode* temp = invertTree(root->left);
        // root->left = invertTree(root->right);
        // root->right = temp;
        // return root;
        TreeNode* temp;
        return root ? (temp = invertTree(root->left), root->left = invertTree(root->right), root->right = temp, root) : root;
        
    }
};
