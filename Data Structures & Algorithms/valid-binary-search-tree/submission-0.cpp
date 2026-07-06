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
    bool isValidBstHelper(TreeNode* root, int lowest, int highest)
    {
        if(!root)
            return true;

        if(root->val < lowest 
        || root->val > highest)
            return false;

        return isValidBstHelper(root->left, lowest, root->val - 1)
            && isValidBstHelper(root->right, root->val + 1, highest);
    }

    bool isValidBST(TreeNode* root) {
        return isValidBstHelper(root, INT_MIN, INT_MAX);
    }
};
