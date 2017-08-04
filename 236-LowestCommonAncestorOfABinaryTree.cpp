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
    int found1 = 0, found2 = 0;
    vector<TreeNode*> num1, num2;

    void find(TreeNode *root, TreeNode *p, vector<TreeNode*> &num, int &found){
        if(root == NULL) return;
        if(root == p){
            num.push_back(root);
            found = 1;
            return;
        }

        if(!found) num.push_back(root);
        find(root->left, p, num, found);
        find(root->right, p, num, found);
        if(!found) num.pop_back();
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* answer = NULL;
        find(root, p, num1, found1);
        find(root, q, num2, found2);
        if(found1*found2 != 1) return answer;

        int len = num1.size();
        int len2 = num2.size();
        answer = NULL;

        for(int i = 0; i < len && i < len2; i++){
            if(num1[i] == num2[i]) answer = num1[i];
            else break;
        }

        return answer;
    }
};
