/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:


    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string answer = "";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();

            if(cur == NULL) answer+="#,";
            else{
                answer = answer + to_string(cur->val) + ",";
                q.push(cur->left);
                q.push(cur->right);
            }
        }

        cout << answer;
        return answer.substr(0, answer.size()-1);

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        cout << "Deserialize;"
        vector<TreeNode*> arr;
        string delim = ",";

        auto start = 0U;
        auto end = s.find(delim);
        while (end != std::string::npos){
            if(s.substr(start, end - start) == "#") arr.push_back(NULL);
            else arr.push_back(new TreeNode(stoi(s.substr(start, end-start))));

            start = end + delim.length();
            end = s.find(delim, start);
        }

        int pos = 0, len = arr.size();
        for(int i = 0; 2*i+2 < len; i++){
            if(arr[i] == NULL) continue;

            arr[i]->left = arr[2*i+1];
            arr[i]->right = arr[2*i+2];
        }

        return arr[0];

    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
