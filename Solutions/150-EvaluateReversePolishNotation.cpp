class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int len = tokens.size(), answer = 0;

        stack<int> stk;
        stk.push(0);

        for(int i = 0; i < len; i++){
            string token = tokens[i];
            if(!token.compare("+") || !token.compare("-") || !token.compare("*") || !token.compare("/")){
                int second = stk.top(); stk.pop();
                int first = stk.top(); stk.pop();

                if(!token.compare("+")) answer = first+second;
                if(!token.compare("-")) answer = first-second;
                if(!token.compare("*")) answer = first*second;
                if(!token.compare("/")) answer = first/second;

                stk.push(answer);
            }else{
                stk.push(stoi(token));
            }
        }

       return stk.top();
    }
};
