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
    long curElement = 0, curCount = 0, maxElement = 0, maxCount = 0;
    vector<int> answer;

    void treeTraversal(TreeNode *root, int explore = 1){
        if(root == NULL) return;
        treeTraversal(root->left, explore);

        if(root->val == curElement){
            curCount += 1;
            if(curCount > maxCount && explore == 1) maxCount = curCount;
            if(curCount == maxCount && explore == 0) answer.push_back(curElement);

        }else{
            curElement = root->val;
            curCount = 1;
            if(maxCount == 1 && explore == 0) answer.push_back(curElement);
        }

        treeTraversal(root->right, explore);
    }

    vector<int> findMode(TreeNode* root) {
        if(root == NULL) return answer;
        int smallestElement;

        TreeNode* temp = root;
        while(temp->left != NULL) temp = temp->left;
        smallestElement = temp->val;

        curElement = smallestElement;
        curCount = 0;
        treeTraversal(root, 1);

        cout << maxCount;
        curCount = 0;
        curElement = smallestElement;
        treeTraversal(root, 0);
        return answer;
    }
};
