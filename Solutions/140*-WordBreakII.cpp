class Solution {
public:
    unordered_set<string> st;
    unordered_map<int, vector<string>> mp;

    vector<string> function(int start, int len, string s){
        vector<string> result;

        if(start == len){
            result.push_back("");
            return result;
        }

        for(int i = start; i < len; i++){
            string word = s.substr(start, i-start+1);
            if(st.find(word) != st.end()){
                if(mp.find(i+1) == mp.end()){
                    mp[i+1] = function(i+1, len, s);
                }

                for(int j = 0; j < mp[i+1].size(); j++){

                    if(mp[i+1][j] == "") result.push_back(word);
                    else result.push_back(word+" "+mp[i+1][j]);
                }
            }
        }

        return result;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int len = wordDict.size();
        for(int i = 0; i < len; i++){
            st.insert(wordDict[i]);
        }

        return function(0, s.size(), s);

    }
};
