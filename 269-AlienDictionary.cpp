class Solution {
public:
    unordered_map<char, unordered_set<char>> g;
    unordered_set<char> st;
    unordered_map<char, int> visit;
    stack<char> stk;
    string answer = "";
    bool cycle = false;

    void TSort(char source){
        if(visit[source]) return;
        visit[source] = 1;

        for(char c: g[source]){
            if(visit[c] == 1) cycle = true;
            TSort(c);
        }

        visit[source] = 2;
        stk.push(source);
    }

    void createGraph(vector<string> words){
        vector<char> fl;
        unordered_map<char, vector<string>> mp;

        for(string word: words){
            if(word.size() > 1)
                mp[word[0]].push_back(word.substr(1, word.size()-1));

            if(fl.size() == 0 || (fl[fl.size()-1] != word[0])) fl.push_back(word[0]);
        }

        int len = fl.size();
        for(int i = 0; i < len-1; i++)  g[fl[i]].insert(fl[i+1]);

        for(char c: fl){
            st.insert(c);
            visit[c] = 0;
            createGraph(mp[c]);
        }
    }

    string alienOrder(vector<string>& words) {
        int len = words.size();
        if(len == 0) return answer;

        createGraph(words);

        for(char c: st) TSort(c);
        while(!stk.empty()){
            answer += stk.top();
            stk.pop();
        }


        if(cycle) return "";
        else return answer;
    }
};
