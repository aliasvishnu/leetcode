// Time - O(mn), where m = number of zeros, n = number of rooms
// Core idea - BFS
// Space complexity - O(mn), for the queue.

class Solution {
public:
    queue<pair<int, int>> q;
    void wallsAndGates(vector<vector<int>>& rooms) {
        int rows = rooms.size();
        if(rows == 0) return;
        int cols = rooms[0].size();

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(rooms[i][j] == 0) q.push(make_pair(i, j));
            }
        }


        while(!q.empty()){
            pair<int, int> top = q.front();

            int r = top.first, c = top.second;
            if(r > 0 && rooms[r-1][c] > 0 && rooms[r-1][c] > 1+rooms[r][c]){
                rooms[r-1][c] = 1+rooms[r][c];
                q.push(make_pair(r-1, c));
            }

            if(c > 0 && rooms[r][c-1] > 0 && rooms[r][c-1] > 1+rooms[r][c]){
                rooms[r][c-1] = 1+rooms[r][c];
                q.push(make_pair(r, c-1));
            }

            if(r < rows-1 && rooms[r+1][c] > 0 && rooms[r+1][c] > 1+rooms[r][c]){
                rooms[r+1][c] = 1+rooms[r][c];
                q.push(make_pair(r+1, c));
            }

            if(c < cols-1 && rooms[r][c+1] > 0 && rooms[r][c+1] > 1+rooms[r][c]){
                rooms[r][c+1] = 1+rooms[r][c];
                q.push(make_pair(r, c+1));
            }

            q.pop();
        }
    }
};
