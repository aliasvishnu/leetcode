class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<string> temp;
        vector<vector<string>> answer;
        for(string s: strs){
            string cp = s;
            sort(cp.begin(), cp.end());
            if(mp.find(cp) == mp.end()) mp[cp] = temp;
            mp[cp].push_back(s);
        }

        unordered_map<string, vector<string>>::iterator it;
        for(it = mp.begin(); it != mp.end(); it++){
            answer.push_back(it->second);
        }
        return answer;
    }
};
