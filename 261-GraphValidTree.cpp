class Solution {
public:
    unordered_map<int, vector<int>> g;
    unordered_map<int, bool> visit;
    unordered_map<int, bool> visitonce; //is true if visited atleast once, to check for disconnected elements

    bool DFS(int i, int parent){
        if(visit[i] == true) return false;

        visit[i] = true;
        visitonce[i] = true;
        bool ans = true;

        for(int node: g[i]){
            if(node != parent && DFS(node, i) == false) ans = false;
        }

        visit[0] = false;
        return ans;
    }

    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> temp;

        for(int i = 0; i < n; i++){
            g[i] = temp;
            visit[i] = false;
            visitonce[i] = false;
        }

        for(auto edge: edges){
            if(edge.first == edge.second) return false;
            g[edge.first].push_back(edge.second);
            g[edge.second].push_back(edge.first);
        }

        bool ans = DFS(0, -1);

        for(int i = 0; i < n; i++)  if(visitonce[i] == false) return false;

        return ans;
    }
};
