class Solution {
public:
    bool checksame(string s, string t, int i, int j){
        cout << i << " " << j << endl;
        while(i < s.size() && j < t.size()){
            if(s[i] != t[j]) return false;
            i++; j++;
        }

        if(i != s.size() || j != t.size()) return false;
        return true;
    }

    bool isOneEditDistance(string s, string t) {

        int i = 0, j = 0, lena = s.size(), lenb = t.size();
        while(i < lena && j < lenb){
            if(s[i] == t[j]){
                i++; j++;
            }else{
                break;
            }
        }

        if(i == lena && j == lenb) return false;
        else return (checksame(s, t, i, j+1) || checksame(s, t, i+1, j) || checksame(s, t, i+1, j+1));
    }
};
