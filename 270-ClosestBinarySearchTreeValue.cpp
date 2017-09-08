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
    int answer = 0;
    float minerror = LONG_MAX;
    void traverse(TreeNode *root, double target){

        if(root == NULL) return;

        if(abs(root->val-target) < minerror){
            answer = root->val;
            minerror = abs(root->val-target);
        }

        if(root->val > target)
            traverse(root->left, target);
        else
            traverse(root->right, target);
    }

    int closestValue(TreeNode* root, double target) {
        traverse(root, target);
        return answer;
    }
};
