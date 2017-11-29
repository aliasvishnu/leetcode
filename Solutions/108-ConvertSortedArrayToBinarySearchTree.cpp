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

    TreeNode* f(int start, int end, vector<int> &nums){
        if(end < start) return NULL;
        int mid = ceil((start+end)/2.0);
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = f(start, mid-1, nums);
        node->right = f(mid+1, end, nums);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        return f(0, nums.size()-1, nums);
    }
};
