class Solution {
public:
    int numDecodings(string s) {
        int len = s.size();
        if(len == 0) return 0;

        unordered_map<int, int> dp;
        dp[-1] = 1;

        if(s[0]-'0' > 0) dp[0] = 1;
        else return 0;

        cout << dp[0] << endl;

        for(int i = 1; i < len; i++){
            if(s[i] == '0'){
                if(s[i-1] == '0') return 0;
                else if(s[i-1] == '1' || s[i-1] == '2') dp[i] = dp[i-2];
                else if(s[i-1] > '2') return 0;
            } else{
                dp[i] = 0;
                dp[i] += (s[i-1] == '0')*dp[i-1];
                dp[i] += (s[i-1] == '1')*(dp[i-1]+dp[i-2]);
                dp[i] += (s[i-1] == '2')*(((s[i]-'0') < 7)?(dp[i-1]+dp[i-2]):dp[i-1]);
                dp[i] += (s[i-1] > '2')*dp[i-1];

                cout << dp[i-1]+dp[i-2];
            }
        }
        return dp[len-1];
    }
};
