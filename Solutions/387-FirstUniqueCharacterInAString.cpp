class Solution {
public:
    int count[26] = {0};
    int firstUniqChar(string s) {
        int len = s.size();

        for(int i = 0; i < len; i++){
            count[s[i]-'a'] += 1;
        }

        for(int i = 0; i < len; i++){
            if(count[s[i]-'a'] == 1) return i;
        }

        return -1;
    }
};
