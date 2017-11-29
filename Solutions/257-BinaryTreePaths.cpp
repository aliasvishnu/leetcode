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
    vector<string> answer;
    vector<int> s;
    string makeString(){
        string ans = "";
        int len = s.size();
        for(int i = 0; i < len-1; i++){
            ans += to_string(s[i]);
            ans += "->";
        }

        if(len != 0) ans += to_string(s[len-1]);

        return ans;
    }

    void traverse(TreeNode* root){
        s.push_back(root->val);
        if(root->left == NULL && root->right == NULL){
            answer.push_back(makeString());
        }

        if(root->left != NULL) traverse(root->left);
        if(root->right != NULL) traverse(root->right);

        s.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL) return answer;
        traverse(root);
        return answer;
    }
};
