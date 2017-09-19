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
    vector<int> vec;

    void convertToList(TreeNode* root){
        if(root==NULL) return;
        convertToList(root->left);
        vec.push_back(root->val);
        convertToList(root->right);
    }



    bool findTarget(TreeNode* root, int k) {
        convertToList(root);
        int start = 0, end = vec.size()-1;
        while(start<end){
            if(vec[start]+vec[end] == k) return true;
            else if(vec[start]+vec[end] < k) start++;
            else end--;
        }
        return false;
    }
};
