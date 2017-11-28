#include <unordered_map>
class Solution {
public:
    unordered_map<char, vector<char>> phone;
    vector<string> answer;

    vector<string> letterCombinations(string digits) {
        int len = digits.size();
        if(len == 0) return answer;

        vector<string> alph = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        for(int i = 0; i < len; i++){
            int num = digits[i]-48;
            vector<string> temp;
            if(alph[num].empty()) return temp;
            string abc = alph[digits[i]-48];
            int l = abc.size();
            for(int j = 0; j < l; j++){
                if(answer.size() == 0) answer.push_back("");
                for(int k = 0; k < answer.size(); k++){
                    temp.push_back(answer[k]+abc[j]);
                }
            }

            answer = temp; // answer.swap(temp) works as well.
        }

        return answer;

    }
};
