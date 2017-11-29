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
