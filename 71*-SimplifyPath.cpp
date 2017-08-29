class Solution {
public:
//     "/a/a//a/.././/...../a/"
//     "/a/a/...../a"

    string simplifyPath(string s) {
        string res, tmp;
        vector<string> stk;
        stringstream ss(path); //splits the stringstream into parts of /

        while(getline(ss,tmp,'/')) {
            if (tmp == "" or tmp == ".") continue;
            if (tmp == ".." and !stk.empty()) stk.pop_back();
            else if (tmp != "..") stk.push_back(tmp);
        }
        for(auto str : stk) res += "/"+str;
        return res.empty() ? "/" : res;

    }
};
