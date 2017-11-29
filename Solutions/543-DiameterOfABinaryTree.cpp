/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int maxVal = 0;

    int depth(TreeNode *root){
        if(root == NULL) return 0;
        int ld = depth(root->left);
        int rd = depth(root->right);
        if(ld+rd > maxVal) maxVal = ld+rd;

        return 1+max(ld, rd);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return maxVal;
    }
};
