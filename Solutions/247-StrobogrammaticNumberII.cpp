class Solution {
public:

    vector<string> helper(int m, int n){
        if(m == 0) return vector<string> {""};
        if(m == 1) return vector<string> {"1", "0", "8"};

        vector<string> strs = helper(m-2, n);

        vector<string> result;
        for(string str: strs){
            if(n!=m)result.push_back("0"+str+"0"); // cannot add 0's on the ends, but can add it in the middle.
            result.push_back("1"+str+"1");
            result.push_back("8"+str+"8");
            result.push_back("6"+str+"9");
            result.push_back("9"+str+"6");
        }

        return result;
    }

    vector<string> findStrobogrammatic(int n) {
        return helper(n, n);
    }
};
