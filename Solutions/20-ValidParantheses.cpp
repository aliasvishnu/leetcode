// BETTER SOLUTION: consider only if number of open braces is ever lesser than number of closing braces and if in the end, any unmatched open braces are remaining. Space complexity would become O(1).
class Solution {
public:
    bool isValid(string s) {
       stack<char> stk;
       int len = s.size();
       for(int i = 0; i < len; i++){
           if(stk.empty()) stk.push(s[i]);
           else{
               if(stk.top() == '(' && s[i] == ')') stk.pop();
               else if(stk.top() == '[' && s[i] == ']') stk.pop();
               else if(stk.top() == '{' && s[i] == '}') stk.pop();
               else stk.push(s[i]);
           }
       }

       return stk.empty();
    }
};
