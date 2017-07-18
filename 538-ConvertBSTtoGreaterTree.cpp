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
        if(root == NULL);
        else{
            cout << "Adding " << sum << " to " << root->val << endl;
            f(root->right);
            int bkp = root->val;
            root->val += sum;
            sum += bkp;
            f(root->left);
        }
    }

    TreeNode* convertBST(TreeNode* root) {
        f(root);
        return root;
    }
};
