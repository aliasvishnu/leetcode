class Solution {
public:
    // We need 1-1 mapping, just come up with logic for that
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int>  mp, mp2;
        int len = s.size();
        int len2 = t.size();
        if(len != len2) return false;

        for(int i = 0; i < len; i++){
            if(mp.find(s[i]) == mp.end()){
                if(mp2.find(t[i]) != mp2.end()) return false;
                mp[s[i]] = t[i];
                mp2[t[i]] = s[i];
            }else{
                if(mp[s[i]] != t[i] || mp2[t[i]] != s[i]) return false;
            }
        }

        return true;

    }
};
