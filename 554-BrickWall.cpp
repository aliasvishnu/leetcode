class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> mp;
        unordered_set<int> st;
        int rows = wall.size();
        int answer = INT_MAX;

        for(int i = 0 ; i < rows; i++){
            for(int j = 0; j < wall[i].size(); j++){
                if(j > 0) wall[i][j] = wall[i][j-1] + wall[i][j];
                // cout << "Wall ends at " << wall[i][j];
                mp[wall[i][j]] = mp[wall[i][j]] + 1;
                st.insert(wall[i][j]);
            }
        }


        unordered_set<int> :: iterator it;
        int max = 0;
        for(it = st.begin(); it != st.end(); it++){
            if(mp[*it] > max && *it != wall[0][wall[0].size()-1]) max = mp[*it];
        }

        if(rows-max < answer) answer = rows-max;

        return answer;
    }
};
