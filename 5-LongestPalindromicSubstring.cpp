class Solution {
public:

    int dp[1000][1000]; //using unordered_map<int, unordered_map<int, int>> causes timeout
    string longestPalindrome(string s) {
        int len = s.size();
        if(len == 0) return "";
        int max = 1, start = 0, alen = 1;
        for(int i = 0; i < len; i++){
            dp[i][i] = 1;
        }

        for(int i = 0; i < len-1; i++){
            dp[i][i+1] = (s[i]==s[i+1])?2:0;
            if(dp[i][i+1] > max){
                max = dp[i][i+1];
                start = i;
                alen = 2;
            }
        }

        for(int i = len-1; i >= 0; i--){
            for(int j = i+2; j < len; j++){
                dp[i][j] = (s[i] == s[j])? (2+dp[i+1][j-1])*(dp[i+1][j-1]!=0):0; //If dp[i+1][j-1] == 0 then dp[i][j] = 0;
                if(dp[i][j] > max){
                    max = dp[i][j];
                    start = i;
                    alen = j-i+1;
                }
            }
        }


        return s.substr(start, alen);
    }
};
