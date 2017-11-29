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

    bool isBST = true;

    pair<int, int> isValBST(TreeNode* root){
        pair<int, int> left, right;
        int minv = root->val, maxv = root->val;

        if(root->left != NULL){
            left = isValBST(root->left);
            if(left.second >= root->val) isBST = false;
            minv = min(left.first, root->val);
        }



        if(root->right != NULL){
            right = isValBST(root->right);
            if(right.first <= root->val) isBST = false;
            maxv = max(right.second, root->val);
        }

        return make_pair(minv, maxv);
    }

    bool isValidBST(TreeNode* root) {
        if(root != NULL) isValBST(root);
        return isBST;
    }
};
