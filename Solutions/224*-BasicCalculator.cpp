class Solution {
public:

    void evaluate(stack<int> &vstack, stack<char> &ostack){
        int second = vstack.top();
        vstack.pop();
        int first = vstack.top();
        vstack.pop();
        // cout << "Evaluating " << first << ostack.top() << second << endl;
        if(ostack.top() == '+') vstack.push(first+second);
        else vstack.push(first-second);
        // cout << "Pushed " << vstack.top() << endl;
        // cout << "Popped " << ostack.top() << endl;
        ostack.pop();
    }

    int calculate(string s) {
        stack<int> vstack;
        stack<char> ostack;

        s = "(" + s + ")";
        int val = 0;
        bool valbuild = false;

        for(char c: s){

            if(c >= '0' && c <= '9'){
                val = val*10+(c-'0');
                valbuild = true;
            }else{
                if(valbuild == true){
                    vstack.push(val);
                    val = 0;
                    valbuild = false;
                }
            }

            if (c == '+' || c == '-'){
                while(!ostack.empty() && (ostack.top() == '+' || ostack.top() == '-')){
                    evaluate(vstack, ostack);
                }
                ostack.push(c);
            }
            else if(c == '(') ostack.push('(');
            else if(c == ')'){
                while(!ostack.empty() && ostack.top() != '('){
                    evaluate(vstack, ostack);
                }
                if(!ostack.empty()) ostack.pop();
            }
        }

        while(!ostack.empty()){
            evaluate(vstack, ostack);
        }

        return vstack.top();
    }
};
