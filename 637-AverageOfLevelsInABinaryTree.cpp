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
    vector<double> answer;

    void BFS(TreeNode *root){
        queue<TreeNode *> q;
        vector<TreeNode *> vec;
        double sum = 0, count = 0;
        q.push(root);
        q.push(NULL);
        vec.push_back(root);
        vec.push_back(NULL);

        while(!q.empty()){
            TreeNode *temp = q.front();
            // (temp!=NULL)? cout << temp->val << endl : cout<< "NULL" << endl;
            q.pop();

            if(temp == NULL){
                if(q.empty()) break;
                else{
                    q.push(NULL);
                    vec.push_back(NULL);
                }
            }else{
                if(temp->left != NULL){
                    q.push(temp->left);
                    vec.push_back(temp->left);
                }
                if(temp->right != NULL){
                    q.push(temp->right);
                    vec.push_back(temp->right);
                }
            }
        }
        int l = vec.size();
        // cout << l << endl;
        for(int i = 0; i < l; i++){

            if(vec[i] != NULL){
                // cout << vec[i]->val << endl;
                sum += vec[i]->val;
                count++;
            }else{
                answer.push_back(sum/count);
                sum = 0;
                count = 0;
            }
        }
    }
    vector<double> averageOfLevels(TreeNode* root) {
        if(root == NULL) return answer;
        BFS(root);
        return answer;
    }
};
