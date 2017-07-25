class Solution {
public:
    vector<vector<int>> answer;

    void dfs(int pos, int rem, int n, vector<int> &curr){
        if(rem == 0){
            answer.push_back(curr);
            return;
        }else if(pos > n){
            return;
        }else{
            dfs(pos+1, rem, n, curr);
            curr.push_back(pos);
            dfs(pos+1, rem-1, n, curr);
            curr.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        dfs(1, k, n, curr);
        return answer;
    }
};
