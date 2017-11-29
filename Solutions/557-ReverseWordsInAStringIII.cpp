class Solution {
public:
    string reverseWords(string s) {
        int start = 0;
        int end = 0;
        int len = s.size();
        for(int i = 0; i < len; i++){
            if(s[i] == ' '){
                if (start < end){
                    reverse(s.begin()+start, s.begin()+end);
                    end += 1;
                    start = end;
                }else if(start == end){
                    start++; end++;
                }
            }else{
                end++;
            }
        }

        if(start < end) reverse(s.begin()+start, s.begin()+end);

        return s;
    }
};
