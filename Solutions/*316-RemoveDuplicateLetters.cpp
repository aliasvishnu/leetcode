class Solution {
public:
    string removeDuplicateLetters(string s) {
        int len = s.size();
        vector<int> count (26, 0);
        vector<bool> inS (26, false);
        string stk = "";

        for(char c: s) count[c-'a']++;

        for(int c: s){
            count[c-'a']--;

            if(stk.empty()){
                stk.push_back(c);
                inS[c-'a'] = true;
                continue;
            }

            if(inS[c-'a']) continue;

            while (!stk.empty() && stk.back() > c && count[stk.back()-'a'] > 0){
                char back = stk.back();
                inS[back-'a'] = false;
                stk.pop_back();
            }

            stk.push_back(c);
            inS[c-'a'] = true;
        }

        return stk;
    }
};
