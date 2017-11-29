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
    int kg = 0;
    int answer = -1;
    int visit(TreeNode* root){
        if(root == NULL) return;

        visit(root->left);
        kg--;
        if(kg == 0){
             return root->val;
        }
        visit(root->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        kg = k;
        if(root == NULL || k == 0) return 0;
        visit(root);
        return answer;
    }
};
