class Solution {
public:

    int minmute = 1000;
    unordered_set<string> nbank;
    vector<char> psb = {'A', 'G', 'C', 'T'};
    unordered_set<string> visited;

    int BFS(string start, string end){
        int depth = 0;
        queue<string> q;
        q.push(start);
        q.push("#");

        while(!q.empty()){
            string s = q.front();
            q.pop();

            // cout << "Current = " << s << endl;

            if(visited.find(s) != visited.end()) continue;
            if(s.compare("#") != 0) visited.insert(s);

            if(s.compare(end) == 0) return depth;

            if(s.compare("#") == 0){
                if(q.empty()) return -1;
                else{
                   q.push("#");
                depth++;
                continue;
                }
            }



            for(int i = 0; i < 8; i++){
                char def = s[i];
                for(char c: psb){
                    s[i] = c;
                    if(visited.find(s) == visited.end() && nbank.find(s) != nbank.end()){
                        q.push(s);
                        // cout << "Pushed " << s << " at depth = " << depth << endl;
                    }
                }
                s[i] = def;
            }
        }

        return -1;
    }

    int minMutation(string start, string end, vector<string>& bank) {

        for(string s: bank){
            nbank.insert(s);
        }

        return BFS(start, end);
    }
};
