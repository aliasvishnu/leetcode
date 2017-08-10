class Solution {
public:


    vector<int> getRow(int rowIndex) {
        int numRows = rowIndex+2;
       vector<vector<int>> ans;
        vector<int> temp (1, 1);
        ans.push_back(temp);
        vector<int> temp2 (2, 1);
        ans.push_back(temp2);
        vector<int> temp3;
        for(int i = 2; i < numRows; i++){
            temp3.clear();
            temp3.push_back(1);
            for(int j = 1; j < i; j++){
                temp3.push_back(ans[i-1][j-1]+ans[i-1][j]);
            }
            temp3.push_back(1);
            ans.push_back(temp3);
        }

        return ans[rowIndex];
    }
};
