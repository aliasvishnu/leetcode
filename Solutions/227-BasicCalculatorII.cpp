class Solution {
public:

    void evaluate(stack<int> &vstack, stack<char> &ostack){
        int second = vstack.top();
        vstack.pop();
        int first = vstack.top();
        vstack.pop();
        // cout << "Evaluating " << first << ostack.top() << second << endl;
        if(ostack.top() == '+') vstack.push(first+second);
        else if(ostack.top() == '-') vstack.push(first-second);
        else if(ostack.top() == '*') vstack.push(first*second);
        else vstack.push(first/second);
        // cout << "Pushed " << vstack.top() << endl;
        // cout << "Popped " << ostack.top() << endl;
        ostack.pop();
    }

    int calculate(string s) {
        stack<int> vstack;
        stack<char> ostack;

        unordered_map<char, int> pref;
        pref['-'] = 0;
        pref['+'] = 0;
        pref['/'] = 1;
        pref['*'] = 1;

        s = "(" + s + ")";
        int val = 0;
        bool valbuild = false;

        for(char c: s){
            // cout << "At " << c << endl;
            if(isdigit(c)){
                val = val*10+(c-'0');
                valbuild = true;
            }else{
                if(valbuild == true){
                    vstack.push(val);
                    // cout << "Pushed " << vstack.top() << endl;
                    val = 0;
                    valbuild = false;
                }
            }

            if (pref.find(c) != pref.end()){
                while(!ostack.empty() && (pref.find(ostack.top()) != pref.end() && pref[ostack.top()] >= pref[c])){
                    evaluate(vstack, ostack);
                }
                ostack.push(c);
                // cout << "Pushed " <<ostack.top() <<endl;
            }
            else if(c == '('){
                ostack.push('(');
                // cout << "Pushed " << ostack.top() <<endl;
            }
            else if(c == ')'){
                while(!ostack.empty() && ostack.top() != '('){
                    evaluate(vstack, ostack);
                }
                if(!ostack.empty()){
                    // cout << "Popped " << ostack.top() <<endl;
                    ostack.pop();
                }
            }
        }

        while(!ostack.empty()){
            evaluate(vstack, ostack);
        }

        return vstack.top();
    }
};
