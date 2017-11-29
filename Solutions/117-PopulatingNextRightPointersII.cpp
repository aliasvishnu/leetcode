/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeLinkNode*> bfs;
    queue<TreeLinkNode*> q;

    void BFS(){

        while(!q.empty()){
            TreeLinkNode *cur = q.front();
            q.pop();

            if(q.empty())
                break;

            if(cur == NULL){
                q.push(NULL);
                bfs.push_back(NULL);
            }
            else{
                if(cur->left != NULL){
                    q.push(cur->left);
                    bfs.push_back(cur->left);
                }

                if(cur->right != NULL){
                    q.push(cur->right);
                    bfs.push_back(cur->right);
                }
            }
        }
    }

    void connect(TreeLinkNode *root) {
        if(root == NULL) return;
        else{
            q.push(root); bfs.push_back(root);
            q.push(NULL); bfs.push_back(NULL);
            BFS();
        }

        int len = bfs.size();
        for(int i = 0; i < len-1; i++){
            if(bfs[i] == NULL) continue;

            bfs[i]->next = bfs[i+1];
        }
    }
};
