class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> answer;

        for(string s: strings){
            int offset = s[0] - 'a';
            string key = "";
            for(char c: s){
                c = c - offset;
                if(c < 'a') c += 26;
                key += string(1, c);
            }

            mp[key].push_back(s);
        }

        unordered_map<string, vector<string>>::iterator it;
        for(it = mp.begin(); it != mp.end(); it++){
            vector<string> temp;
            vector<string>:: iterator is;
            for(is = (it->second).begin(); is != (it->second).end(); is++){
                temp.push_back(*is);
            }
            sort(temp.begin(), temp.end());
            answer.push_back(temp);
        }

        return answer;
    }
};
