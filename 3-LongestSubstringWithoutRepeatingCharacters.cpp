class Solution {
public:
    unordered_map<char, int> prev;

    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        if(len == 0) return 0;

        int start = 0, maxCount = -1000;
        for(int i = 0; i < len; i++){
            if(prev.find(s[i]) == prev.end()){
                prev[s[i]] = i;
                if(i-start > maxCount) maxCount = i-start;
            }
            else{
                while(prev.find(s[i]) != prev.end()){
                    prev.erase(s[start++]);
                }
                prev[s[i]] = i;
            }
        }

        return maxCount+1;
    }
};
