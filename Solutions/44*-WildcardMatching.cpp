class Solution {
public:
    bool isMatch(string s, string p) {
        s.insert(s.begin(), 1, '-');
        p.insert(p.begin(), 1, '-');
        int n = s.size();
        int m = p.size();

        vector<int> temp;
        for(int i = 0; i < n; i++)temp.push_back(false);
        vector< vector<int> > M;
        for(int i = 0; i < m; i++) M.push_back(temp);


        M[0][0] = true;

        for(int i = 1; i < m; i++){
            if(p[i] == '*') M[i][0] = M[i-1][0];
        }

        // Try solving (10. Regular Expression Matching) first


        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(p[i] != '*'){
                    if(M[i-1][j-1] == true && (s[j] == p[i] || p[i] == '?')) M[i][j] = true;
                }else{
                    M[i][j] = M[i-1][j] || M[i][j-1];
                    // M[i-1][j-1] will be true if M[i-1][j] is true
                }
            }

        }

        return M[m-1][n-1];
    }
};
