class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if(numRows == 0) return ans;
        vector<int> temp (1, 1);
        ans.push_back(temp);
        if(numRows  == 1) return ans;

        vector<int> temp2 (2, 1);
        ans.push_back(temp2);

        if(numRows == 2) return ans;

        vector<int> temp3;
        for(int i = 2; i < numRows; i++){
            temp3.clear();
            temp3.push_back(1);
            for(int j = 1; j < i; j++){
                cout << ans[i-1][j-1];
                temp3.push_back(ans[i-1][j-1]+ans[i-1][j]);
            }
            temp3.push_back(1);
            ans.push_back(temp3);
        }

        return ans;
    }
};
