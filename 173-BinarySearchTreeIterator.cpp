/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> stk;
    vector<int> store;
    BSTIterator(TreeNode *root) {
    TreeNode *temp = root;
       while(temp != NULL){
           stk.push(temp);
           temp = temp->left;
       }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        // cout << "HasNext:" << !stk.empty() << endl;
        return !stk.empty();
    }

    /** @return the next smallest number */
    int next(){
        TreeNode *temp, *temp2;
        temp = stk.top(), temp2 = stk.top();
        stk.pop();

        if(temp->right != NULL){
            temp = temp->right;
            while(temp != NULL){
                stk.push(temp);
                temp = temp->left;
            }
        }

        return temp2->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
