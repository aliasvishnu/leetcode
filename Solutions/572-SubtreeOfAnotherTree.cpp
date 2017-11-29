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
    string sstr=",", tstr=",";

    void traverse(TreeNode *s, string &str){
        if(s == NULL){
            str += "#";
            str += ",";
            return;
        }


        str += to_string(s->val);
        str += ",";
        traverse(s->left, str);
        traverse(s->right, str);
    }

    bool search(string s, string t){
        int lena = s.size(), lenb = t.size();
        for(int i = 0; i < lena; i++){
            if(s[i] == t[0]){
                int j = 0;
                for(j = 0; j < lenb; j++){
                    if(s[i+j] != t[j]) break;
                }
                if(j == lenb) return true;
            }
        }

        return false;
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(t == NULL){
            if(s == NULL) return true;
            else return false;
        }

        traverse(s, sstr);
        traverse(t, tstr);

        return search(sstr, tstr);
    }
};
