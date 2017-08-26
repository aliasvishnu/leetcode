struct node{
    char c;
    vector<node *> lst;
    node(char k){
        c = k;
        for(int i = 0; i < 27; i++) lst.push_back(NULL);
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    struct node *root;
    Trie() {
        root = new node('#');
    }

    struct node* getRoot(){
        return root;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        struct node *temp = root;
        int len = word.size();
        for(int i = 0; i < len; i++){
            if(temp->lst[word[i]-96] == NULL){
                temp->lst[word[i]-96] = new node(word[i]-97);
            }
            temp = temp->lst[word[i]-96];
        }
        temp->lst[0] = new node('#');
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        struct node *temp = root;
        int len = word.size();
        for(int i = 0; i < len; i++){
            if(temp->lst[word[i]-96] == NULL) return false;
            else temp = temp->lst[word[i]-96];
        }
        return temp->lst[0] != NULL;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        struct node *temp = root;
        int len = prefix.size();
        for(int i = 0; i < len; i++){
            if(temp->lst[prefix[i]-96] == NULL) return false;
            else temp = temp->lst[prefix[i]-96];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

class Solution {
public:
    vector<string> answer;
    int rows, cols;

    bool insideBounds(int r, int c){
        if(r < 0 || r >= rows || c < 0 || c >= cols) return false;
        return true;
    }

    string tostring(char c){
        string s (1, c);
        return s;
    }

    void DFS(vector<vector<char>>& M, struct node *root, int r, int c, string newword){
        if(root->lst[0] != NULL){
            if(root->lst[0]->c == '#'){
                root->lst[0]->c = '@';
                answer.push_back(newword);
            }
        }

        if(M[r][c] == '#' || root->lst[M[r][c]-96] == NULL) return;

        char bkp = M[r][c];
        M[r][c] = '#';


        if(insideBounds(r+1, c)) DFS(M, root->lst[M[r+1][c]-96], r+1, c, newword+tostring(M[r+1][c]));
        if(insideBounds(r, c+1)) DFS(M, root->lst[M[r][c+1]-96], r, c+1, newword+tostring(M[r][c+1]));
        if(insideBounds(r-1, c)) DFS(M, root->lst[M[r-1][c]-96], r-1, c, newword+tostring(M[r-1][c]));
        if(insideBounds(r, c-1)) DFS(M, root->lst[M[r][c-1]-96], r, c-1, newword+tostring(M[r][c-1]));

        M[r][c] = bkp;
    }


    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie *obj = new Trie();
        int len = words.size();

        for(int i = 0; i < len; i++){
            obj->insert(words[i]);
        }

        rows = board.size();
        cols = board.size();

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                DFS(board, obj->getRoot(), i, j, "");
            }
        }

        return answer;

    }
};
