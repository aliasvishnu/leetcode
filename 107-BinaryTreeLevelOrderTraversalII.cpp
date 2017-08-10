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

    queue<TreeNode*> q;
        vector<vector<int>> answer;

        void dfs(TreeNode* root){
            vector<int> cur;
            q.push(root);
            q.push(NULL);

            while(!q.empty()){
                TreeNode*temp = q.front();
                q.pop();
                if(temp == NULL){
                    answer.push_back(cur);
                    if(q.empty()) return;
                    q.push(NULL);
                    cur.clear();
                    continue;
                }
                else cur.push_back(temp->val);

                if(temp->left != NULL) q.push(temp->left);
                if(temp->right != NULL) q.push(temp->right);
            }
        }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == NULL) return answer;

        dfs(root);
        reverse(answer.begin(), answer.end());
        return answer;
    }
};
