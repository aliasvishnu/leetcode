class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> mp;
        mp['0'] = '0';
        mp['1'] = '1';
        mp['6'] = '9';
        mp['8'] = '8';
        mp['9'] = '6';

        int len = num.size();

        for(int i = 0; i <= len/2; i++){
            if(mp.find(num[i]) == mp.end() || mp.find(num[len-i-1]) == mp.end()) return false;
            else if(mp[num[i]] != num[len-i-1]) return false;
        }

        return true;
    }
};
