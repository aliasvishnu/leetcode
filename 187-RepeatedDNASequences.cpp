class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int len = s.size();
        unordered_set<string> st, ans;
        vector<string> answer;
        for(int i = 0; i < len-9; i++){
            string temp = s.substr(i, 10);
            if(st.find(temp) == st.end()) st.insert(temp);
            else if(ans.find(temp) == ans.end()){
                answer.push_back(temp);
                ans.insert(temp);
            }
        }
        return answer;
    }
};
