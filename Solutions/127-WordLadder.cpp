class Solution {
public:
    unordered_map<int, vector<int>> g;
    vector<int> visit;
    int minanswer = INT_MAX;

    bool matches(string a, string b){
        int lena = a.size();
        int lenb = b.size();
        int errorcount = 0;
        if(lena != lenb) return false;

        errorcount = 0;
        for(int i = 0; i < lena; i++){
            if(a[i] != b[i]) errorcount++;
        }

        if(errorcount == 1) return true;
        return false;
    }

    int find(vector<string>& wordList, string word, int len){
        for(int i = 0; i < len; i++)
            if(wordList[i].compare(word) == 0) return i;
        return -1;
    }


    queue<int> q;
    int BFS(int source, int destination){
        q.push(source);
        q.push(-1);
        int depth = 1;

        while(!q.empty()){
            if(q.size() == 1 && q.front() == -1) return INT_MAX;

            int cur = q.front();
            q.pop();

            if(cur == -1) {
                q.push(-1);
                depth++;
            }
            else for(int i = 0; i < g[cur].size(); i++){
                if(g[cur][i] == destination) return depth;
                if(visit[g[cur][i]] == 0){
                    q.push(g[cur][i]);
                    visit[g[cur][i]] = 1;
                }

            }
        }

        return INT_MAX;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordListOriginal) {
        int len = wordListOriginal.size(), source = -1, destination = -1;

        // construct a set of unique words
        unordered_set<string> setofstrings;
        for(int i = 0; i < len; i++){
            setofstrings.insert(wordListOriginal[i]);
        }

        vector<string> wordList;
        unordered_set<string>:: iterator it;
        for(it = setofstrings.begin(); it != setofstrings.end(); it++){
            wordList.push_back(*it);
        }
        len = wordList.size();

        if((source=find(wordList, beginWord, len)) == -1){
            wordList.push_back(beginWord);
            source = len++;
        }

        if((destination=find(wordList, endWord, len)) == -1) return 0;

        // construct graph
        for(int i = 0; i < len-1; i++){
            visit.push_back(0);
            for(int j = i+1; j < len; j++){
                if(matches(wordList[i], wordList[j])){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        visit.push_back(0);

        int ans = BFS(source, destination);

        if(ans == INT_MAX) return 0;
        else return ans+1;
    }
};
