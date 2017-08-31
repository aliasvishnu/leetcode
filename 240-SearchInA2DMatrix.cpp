class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if(rows == 0) return false;
        int cols = matrix[0].size();
        if(cols == 0) return false;

        int i = 0, j = cols-1;
        while(1){
            if(target == matrix[i][j]) return true;
            else if(target < matrix[i][j] && j-1 >= 0) j -= 1;
            else if(target > matrix[i][j] && i+1 < rows) i += 1;
            else return false;
        }
    }
};
