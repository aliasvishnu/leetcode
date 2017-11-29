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

    bool find(TreeNode *root, TreeNode *p, TreeNode *q){
        if(root == NULL) return false;
        if(root == p || root == q) return true;
        return find(root->left, p, q) || find(root->right, p, q);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(root == p || root == q) return root;
        else if(root == NULL) return NULL;
        else if(find(root->left, p, q) && find(root->right, p, q)) return root;
        else{
            TreeNode *left = lowestCommonAncestor(root->left, p, q);
            TreeNode *right = lowestCommonAncestor(root->right, p, q);
            return (left == NULL)? right:left;
        }
    }
};
