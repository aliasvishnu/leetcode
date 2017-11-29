class Solution {
public:
    bool validPalindrome(string s) {
        int len = s.size();
        int count = 0, i = 0, j = len-1;

        while(i < j){
            if(s[i] != s[j]){
                count++;
                j--;
                continue;
            }
            i++;
            j--;
        }

        if(count <= 1) return true;

        i = 0; j = len-1;
        count = 0;
        while(i < j){
            if(s[i] != s[j]){
                count++;
                i++;
                continue;
            }
            i++;
            j--;
        }

        if(count <= 1) return true;

        return false;
    }
};
