class Solution {
public:
    vector<int> stk;
    map<int, vector<int> > g;
    unordered_set<int> visited, visiting;

    int DFS(map<int, vector<int> > &g, int source){
        visiting.insert(source);
        int len = g[source].size();
        int r = 1;
        for(int i = 0; i < len; i++){
            if(visiting.find(g[source][i]) != visiting.end()) return 0;
            if(visited.find(g[source][i]) == visited.end()) r *= DFS(g, g[source][i]);
        }

        visited.insert(source);
        visiting.erase(source);
        stk.push_back(source);
        return r;
    }


    vector<int> findOrder(int numCourses, vector<pair<int, int>>& preq) {


        int len = preq.size();
        for(int i = 0; i < len; i++){
            g[preq[i].second].push_back(preq[i].first);
        }

        int r = 1;
        for(int i = 0; i < numCourses; i++){
            if(visited.find(i) == visited.end()) r *= DFS(g, i);
        }

        vector<int> empty;
        reverse(stk.begin(), stk.end());

        return (r == 0)? empty:stk;
    }
};
