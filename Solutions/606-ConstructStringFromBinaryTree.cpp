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

    string answer = "";

    void f(TreeNode* t){
        if(t == NULL) return;
        answer += to_string(t->val);
        if(t->left == NULL && t->right == NULL);
        else{
            answer += "(";
            if(t->left != NULL) f(t->left);
            answer += ")";

            if(t->right != NULL){
                answer += "(";
                f(t->right);
                answer += ")";
            }
        }
    }

    string tree2str(TreeNode* t) {
        f(t);
        return answer;
    }
};
