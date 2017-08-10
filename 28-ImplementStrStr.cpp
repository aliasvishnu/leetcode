class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.size();
        int len2 = needle.size();
        bool in = false;
        for(int i = 0; i < len1-len2+1; i++){
            in = true;
            for(int j = 0; j < len2; j++){
                if(haystack[i+j] != needle[j]) in = false;
            }

            if(in == true) return i;
        }

        return -1;
    }
};
