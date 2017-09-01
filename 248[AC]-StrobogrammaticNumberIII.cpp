class Solution {
public:

    int answer = 0;
    // is A less than or equal to B
    bool lessthan(string a, string b){
        if(a.size() < b.size()) return true;
        else if(b.size() < a.size()) return false;
        else{

            int len = a.size(), i = 0;
            while(i < len && a[i] == b[i]) i++;
            return (i == len || (a[i] < b[i]));
        }
    }

    // between low and high
    bool between(string low, string high, string num){
        if(lessthan(low, num) && lessthan(num, high)) return true;
        else return false;
    }

    vector<string> helper(int m, int n, string low, string high){
        if(m == 0) return vector<string> {""};
        if(m == 1) return vector<string> {"1", "0", "8"};

        vector<string> strs = helper(m-2, n, low, high);

        vector<string> result;
        for(string str: strs){
            if(n!=m)result.push_back("0"+str+"0"); // cannot add 0's on the ends, but can add it in the middle.
            result.push_back("1"+str+"1");
            result.push_back("8"+str+"8");
            result.push_back("6"+str+"9");
            result.push_back("9"+str+"6");
        }

        for(string s: result) if(between(low, high, s) && s[0] != '0') answer++;

        return result;
    }

    int strobogrammaticInRange(string low, string high) {
        vector<string> digit {"0", "1", "8"};

        for(string s:digit) if(between(low, high, s)) answer++;
        int n = high.size();

        helper(n, n, low, high);
        helper(n-1, n-1, low, high);

        return answer;
    }
};
