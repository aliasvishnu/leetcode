class Solution {
public:

    unordered_map<char, int> count;
    unordered_map<char, int> requiredCount;

    string minWindow(string s, string t) {
        int tlen = t.size();
        int unique = 0;
        for(int i = 0; i < tlen; i++){
            if(count.find(t[i]) == count.end()){
                unique++;
                requiredCount[t[i]] = 0;
            }
            count[t[i]] = 0;
            requiredCount[t[i]] += 1;
        }

        int answerStart = 0, answerEnd = s.size()-1, start = -1, end = -1, sunique = 0;
        bool flag = false;
        int slen = s.size();
        while(start <= end && end < slen){
            if(sunique < unique){
                end++;
                if(count.find(s[end]) != count.end()){
                    count[s[end]] += 1;
                    if(count[s[end]] == requiredCount[s[end]]) sunique += 1;
                }
            }else{
                if(count.find(s[start]) != count.end()){
                    if(count[s[start]] == requiredCount[s[start]]) sunique--;
                    count[s[start]]-= 1;
                }
                start++;
            }
            if(sunique == unique ){
                flag = true;
                if(end-start+1 < answerEnd-answerStart+1){
                    answerEnd = end;
                    answerStart = start;
                }
            }
        }

        if(flag) return s.substr(answerStart, answerEnd-answerStart+1);
        else return "";
    }
};
