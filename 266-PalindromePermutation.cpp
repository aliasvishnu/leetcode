class Solution {
public:
    bool canPermutePalindrome(string s) {
        int count[256] = {}, sum = 0, len = s.size();

        // bit obfuscated
        for(int i = 0; i < len; i++){
            sum += (count[s[i]])? -1:1; // if it is turning to 0, reduce 1 from sum.
            count[s[i]] = (count[s[i]]+1)%2;  // make it zero when even pairs are found.
        }
        return sum<=1;
    }
};
