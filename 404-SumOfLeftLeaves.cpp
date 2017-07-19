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
    int sum = 0;
    void f(TreeNode *root){
        if(root == NULL) return;
        if(root->left != NULL && root->left->left == NULL && root->left->right == NULL){
            sum += root->left->val;
        }
        f(root->left);
        f(root->right);
    }


    int sumOfLeftLeaves(TreeNode* root) {
       f(root);
        return sum;
    }
};
