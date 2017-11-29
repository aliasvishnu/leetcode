class Solution {
public:

    unordered_map<int, int> visit;
    unordered_map<int, vector<int>> g;

    bool cycleDetect(int node){
        vector<int> ::iterator it;
        visit[node] = 1;
        bool answer = true;
        cout << "Visiting " << node << endl;
        for(it = g[node].begin(); it != g[node].end(); it++){
            cout << "Child " << *it <<  " . " << visit[*it] << endl;
            if(visit[*it] == 1) answer = false;
            else if(visit[*it] == 0){
                 if(cycleDetect(*it) == false){
                     answer = false;
                 }
            }

        }
        visit[node] = 2;
        return answer;
    }

    bool canFinish(int numCourses, vector<pair<int, int> >& prq) {
        int len = prq.size();
        if(len <= 1)  return true;

        vector<pair<int, int>> ::iterator it;
        for(it = prq.begin(); it != prq.end(); it++){

            g[it->second].push_back(it->first);
            visit[it->second] = 0;
            visit[it->first] = 0;
        }

        bool flag = false;
        for(int i = 0; i < numCourses; i++){
            if(visit[i] == 0){
                if(cycleDetect(i) == false) return false;
            }
        }

        return true;
    }
};
