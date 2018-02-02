class Solution {
public:
    int largestRectangleArea(vector<int>& V) {
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
};
