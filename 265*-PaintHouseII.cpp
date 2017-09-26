class Solution {
public:


    int minCostII(vector<vector<int>>& costs) {
        int rows = costs.size();
        if(rows == 0) return 0;
        int cols = costs[0].size();
        int min1 = -1, min2 = -1, fi = -1, si = -1;


        for(int i = 0; i < rows; i++){
            fi = min1; si = min2;
            min1 = -1; min2 = -1;

            for(int j = 0; j < cols; j++){

                if(j != fi){
                    if(fi >= 0)
                        costs[i][j] += costs[i-1][fi];

                }else{
                    if(si >= 0)
                        costs[i][j] += costs[i-1][si];
                }

                if(min1 == -1 || costs[i][j] < costs[i][min1]){
                    min2 = min1;
                    min1 = j;
                }else if(min2 == -1 || costs[i][j] < costs[i][min2]){
                    min2 = j;
                }

                // cout << costs[i][j] << " ";
            }

        }

        return costs[rows-1][min1];
    }
};
