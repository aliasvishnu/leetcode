class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> answer;
        int rows = matrix.size();
        if(rows == 0) return answer;

        int cols = matrix[0].size();
        int count = rows*cols;
        int dir = 1, delr, delc;
        int i = 0, j = -1;
        // 1 - right, 2 - down, 3 - left, 0 - up
        rows -= 1;
        while(count > 0){
            // cout << "Remaining elements = " << count << endl;
            int lim = 0;
            if(dir == 1){lim = cols;delc = 1, delr = 0;}
            else if(dir == 2){lim = rows;delc = 0, delr = 1;}
            else if(dir == 3){lim = cols;delc = -1, delr = 0;}
            else {lim = rows;delc = 0, delr = -1;}


            for(int k = 0; k < lim; k++){
                cout << "i = " << i << " j = " << j << endl;
                i += delr;
                j += delc;
                cout << matrix[i][j] << " ";
                answer.push_back(matrix[i][j]);
                count--;
            }
            rows -= delr*delr;
            cols -= delc*delc;
            dir = (dir+1)%4;
        }

        return answer;
    }
};
