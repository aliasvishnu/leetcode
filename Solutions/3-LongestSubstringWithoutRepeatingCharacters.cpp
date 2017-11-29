class Solution {
public:
    unordered_map<char, int> prev;

    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        if(len == 0) return 0;

        unordered_map<char, int> prev;
        int start = 0, answer = -1;

        for(int i = 0; i < len; i++){
            if(prev.find(s[i]) == prev.end() || prev[s[i]] < start){
                if(answer < i-start+1) answer = i-start+1;
            }else{
                start = prev[s[i]]+1;
            }

            prev[s[i]] = i;
        }
        return answer;
    }

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
