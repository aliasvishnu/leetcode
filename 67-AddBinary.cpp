class Solution {
public:
    string addBinary(string a, string b) {
        int l1 = a.size();
        int l2 = b.size();
        int rem  = 0;
        string s = "";
        int i = l1-1, j = l2-1;
        // cout << atoi(a[i]);

        while(i >= 0 && j >= 0){

            int x = a[i]-'0';
            int y = b[j]-'0';

            cout << "Adding " << x << " and " << y << " and " << rem << endl;
            int res = (x+y+rem)%2;
            rem = (x+y+rem)/2;
            s = to_string(res)+s;
            i--; j--;
        }

        while(i >= 0){
            int x = a[i]-'0';
            int res = (x+rem)%2;
            rem = (x+rem)/2;
            s = to_string(res)+s;
            i--;
        }

        while(j >= 0){
            int x = b[j]-'0';
            int res = (x+rem)%2;
            rem = (x+rem)/2;
            s = to_string(res)+s;
            j--;
        }

        if(rem != 0) s = to_string(rem)+s;

        i = 0;
        while(s[i] == '0') i++;
        cout << s;
        string ans (s.begin()+i, s.end());

        return (ans.empty())?"0":ans;
    }
};
