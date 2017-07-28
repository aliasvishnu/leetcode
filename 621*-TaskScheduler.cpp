#include <priority_queue>
class Solution {
public:

    priority_queue<int> q;
    unordered_map<char, int> mp;

    int leastInterval(vector<char>& tasks, int n) {
        int time = 0;

        int len = tasks.size();
        for(int i = 0; i < len; i++){
            if(mp.find(tasks[i]) == mp.end()) mp[tasks[i]] = 0;
            mp[tasks[i]] += 1;
        }

        unordered_map<char, int> ::iterator it;
        for(it = mp.begin(); it != mp.end(); it++){
            q.push(it->second);
        }


        while(q.size() > n){
            vector<int> temp;
            for(int j = 0; j < (n+1); j++){
                temp.push_back(q.top()-1);
                time += 1;
                q.pop();
            }
            for(int j = 0; j < (n+1); j++){
                if(temp[j] > 0)
                    q.push(temp[j]);
            }
        }

        int count = 0;
        if(!q.empty() && q.top() != 0) {
            int val = q.top();
            q.pop();
            while(!q.empty() && q.top() == val){
                count += 1;
                q.pop();
            }

            time +=(1+n)*val + count-n;
        }
        return time;

    }
};
