class Solution {
public:
    // is A less than or equal to B
    bool lessthan(string &a, string &b){
        if(a.size() < b.size()) return true;
        else if(b.size() < a.size()) return false;
        else{

            int len = a.size(), i = 0;
            while(i < len && a[i] == b[i]) i++;
            return (i == len || (a[i] < b[i]));
        }
    }

    // between low and high
    bool between(string &low, string &high, string &num){
        if(lessthan(low, num) && lessthan(num, high)) return true;
        else return false;
    }

    int strobogrammaticInRange(string low, string high) {
        vector<string> secondlast {""};
        vector<string> last {"0", "1", "8"};

        int n = high.size(), answer = 0;


        for(string s : last){
            if(between(low, high, s)) answer++;
        }
         vector<string> temp;

        for(int r = 1; r <= n; r += 1){
            temp.clear();

            for(string s: secondlast){
                if(s.size()+2 < n)temp.push_back("0"+s+"0");
                temp.push_back("1"+s+"1");
                temp.push_back("8"+s+"8");
                temp.push_back("9"+s+"6");
                temp.push_back("6"+s+"9");
            }

            secondlast = last;
            last = temp;
            
            int l = temp.size();
            for(int j = 0; j < l; j++){

                string s = temp[j];
                // cout << s << endl;
                if(between(low, high, s) && s[0] != '0'){
                    // cout << s << endl;
                    answer++;
                }
            }

        }



        return answer;
    }
};
