class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        int len = strs.size();
        string ans = "";
        for(string s: strs){
            ans += to_string(s.size());
            ans += "/";
            ans += s;
        }
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        int i = 0, len = s.size();
        vector<string> answer;
        while(i < len){
            int num = 0;
            while(i < len && s[i] != '/') num = num*10 + (s[i++]-48);
            i++;
            answer.push_back(s.substr(i, num));
            i += num;
        }

        return answer;
    }
};
