// Time - O(n)
// Space - O(n)
// Main idea - UnorderedMap and Set
class ValidWordAbbr {
public:
    unordered_map<string, int> mp;
    unordered_set<string> st;
    ValidWordAbbr(vector<string> dictionary) {
        for(string s: dictionary){
            if(s.size() <= 2){
                if(mp.find(s) == mp.end()) mp[s] = 0;
                cout << s << endl;
                 if(st.find(s) == st.end()) mp[s]++;
            }else{
                string key = string(1, s[0]) + to_string(s.size()-2) + string(1, s[s.size()-1]);
                if(mp.find(key) == mp.end()) mp[key] = 0;
                cout << key << endl;
                if(st.find(s) == st.end()) mp[key]++;
            }
            st.insert(s);
        }
    }

    bool isUnique(string s) {
        if(s.size() <= 2) return (mp.find(s) == mp.end() || mp[s] == 1);
        else {
            string key = string(1, s[0]) + to_string(s.size()-2) + string(1, s[s.size()-1]);
            if(st.find(s) == st.end()) return mp.find(key) == mp.end();
            else if(st.find(s) != st.end()) return mp[key] == 1;
        }
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */
