class Solution {
public:

    int calculateMaxRectangle(vector<int> V){
        stack<int> stk;

        int len = V.size(), i = 0, answer = 0;

        while(i < len){

            if(stk.empty() || V[stk.top()] < V[i]){
                stk.push(i++);
            } else {
                int ind = stk.top();
                stk.pop();

                 // compute height.
                int candidate = V[ind] * ((stk.empty())? i: i - stk.top() - 1 );
                answer = (candidate > answer)? candidate: answer;
            }

        }

        while(!stk.empty()){
            int ind = stk.top();
            stk.pop();

             // compute height.
            int candidate = V[ind] * ((stk.empty())? i: i - stk.top() - 1 );
            answer = (candidate > answer)? candidate: answer;
        }

        return answer;
    }

    int maximalRectangle(vector<vector<char>>& M) {
        int rows = M.size();
        if(rows == 0) return 0;
        int cols = M[0].size();

        vector<vector<int>> TC (rows, vector<int> (cols, 0));

        int answer = 0;

        for(int i = 0; i < cols; i++) TC[0][i] = M[0][i] == '1';

        for(int i = 1; i < rows; i++){
            for(int j = 0; j < cols; j++){
                TC[i][j] = (M[i][j] == '1') ? TC[i-1][j] + 1: 0;
            }
        }


        for(int i = 0; i < rows; i++){
            int max_rectangle = calculateMaxRectangle(TC[i]);
            if(max_rectangle > answer){
                answer = max_rectangle;
            }
        }

        return answer;
    }
};
