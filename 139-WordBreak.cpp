#include <algorithm>
class Solution {
public:

    bool contains(string s, vector<string>& d){
        return (find(d.begin(), d.end(), s) != d.end());
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        vector<int> dp (s.size()+1, false);

        if(len == 0) return true;
        dp[0] = true;
        //  We have dp until j, we want to extend from j to i, and i will be pushed to len;

        for(int i = 1; i <= len; i++){
            for(int j = 0; j < i; j++){
                if(dp[j] && contains(s.substr(j, i-j), wordDict)){
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[len];
    }
};
