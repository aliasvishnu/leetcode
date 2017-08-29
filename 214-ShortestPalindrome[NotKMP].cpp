class Solution {
public:
    bool checkPalin(int start, int end, string &s){
        while(start <= end){
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }

        return true;
    }

    string shortestPalindrome(string s) {
        int len = s.size();

        for(int i = len-1; i >= 0; i--){
            if(checkPalin(0, i, s) == true){
                cout << i << endl;
                string c = s.substr(i+1, len-i-1);
                reverse(c.begin(), c.end());
                string newstring = c+s;
                return newstring;
            }
        }

        return s;
    }
};
