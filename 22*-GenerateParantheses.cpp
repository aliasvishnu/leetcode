/*
If less than n open brackets are open, we can add open bracket. But to add a close bracket you need #close < #open.
*/

class Solution {
public:
    vector<string> answer;

    void backtrack(int n, int open, int close, string s){
        if(s.size() == 2*n) {
            answer.push_back(s);
            return;
        }

        if(open < n){
            backtrack(n, open+1, close, s+"(");
        }
        if(close < open){
            backtrack(n, open, close+1, s+")");
        }
    }

    vector<string> generateParenthesis(int n) {
        string s = "";
        backtrack(n, 0, 0, s);
        return answer;
    }
};
