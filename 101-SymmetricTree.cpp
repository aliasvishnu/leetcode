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
    bool isSym(TreeNode *Left, TreeNode *Right){
        if(Left == NULL && Right == NULL) return true;
        if(Left == NULL || Right == NULL) return false;

        return (Left->val == Right->val) & isSym(Left->left, Right->right) & isSym(Left->right, Right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return isSym(root->left, root->right);
    }
};
