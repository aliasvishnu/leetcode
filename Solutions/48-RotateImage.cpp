#include <math>
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return;

        for(int i = 0; i < n/2; i++){
            for (int j = 0; j < ceil(n*1.0/2); j++){
                for(int k = 0; k < 3; k++){
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[j][n-i-1];
                    matrix[j][n-i-1] = matrix[n-i-1][n-j-1];
                    matrix[n-i-1][n-j-1] = matrix[n-j-1][i];
                    matrix[n-j-1][i] = temp;
                }
            }
        }


    }
};
