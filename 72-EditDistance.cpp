class Solution {
public:
    int minDistance(string word1, string word2) {
        word1 = " " + word1;
        word2 = " " + word2;

        int len1 = word1.size(), len2 = word2.size();

        vector<vector<int>> DP (len1+1, vector<int> (len2+1, INT_MAX));

        DP[0][0] = 0;
        for(int i = 0; i <= len1; i++) DP[i][0] = i;
        for(int i = 0; i <= len2; i++) DP[0][i] = i;

        for(int i = 1; i <= len1; i++){
            for(int j = 1; j <= len2; j++){
                if(word1[i] == word2[j])
                    DP[i][j] = DP[i-1][j-1];
                else
                    DP[i][j] = 1 + min(DP[i-1][j], min(DP[i][j-1], DP[i-1][j-1]));
            }
        }

        return DP[len1][len2];

    }
};
