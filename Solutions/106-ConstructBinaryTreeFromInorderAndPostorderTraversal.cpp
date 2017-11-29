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
    stack<int> q;
    TreeNode* makeRoot(int r){
        return new TreeNode(r);
    }

    // Just check problem 105, I have changed queue to stack and filled root->right first
    TreeNode* makeTree(vector<int> &preorder, vector<int> &inorder, int start, int end){

        if(start > end) return NULL;
        int r = q.top();
        q.pop();

        TreeNode* root = makeRoot(r);
        int index = find(inorder.begin()+start, inorder.begin()+end, r)-inorder.begin();
        root->right = makeTree(preorder, inorder, index+1, end);
        root->left = makeTree(preorder, inorder, start, index-1);

        return root;

    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int len = postorder.size();
        if(len == 0) return NULL;

        for(int i = 0;i < len; i++){
            q.push(postorder[i]);
        }
        return makeTree(postorder, inorder, 0, len-1);
    }
};
