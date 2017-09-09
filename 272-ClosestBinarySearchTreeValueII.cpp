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
    vector<int> sorted;

    void traverse(TreeNode* root){
        if(root == NULL) return;

        traverse(root->left);
        sorted.push_back(root->val);
        traverse(root->right);
    }

    vector<int> closestKValues(TreeNode* root, double target, int k) {
        traverse(root);
        int len = sorted.size();
        int prev = 0;
        for(int i = 0; i < len; i++){
            if(sorted[i] < target) prev = i;
        }
        int next = len;
        for(int i = len-1; i >= 0; i--){
            if(sorted[i] > target) next = i;
        }

        int count = next-prev-1;
        while(count < k){
            if(prev < 0) next++;
            else if (next >= len) prev--;
            else if(abs(target-sorted[prev]) <= abs(target-sorted[next])) prev--;
            else if(abs(target-sorted[prev]) > abs(target-sorted[next])) next++;
            count++;
        }

        vector<int> answer;
        for(int i = prev+1; i < next; i++) answer.push_back(sorted[i]);
        return answer;
    }
};
