class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), [](int a, int b){ return a > b;});

        int len = citations.size();
        if(len == 0) return 0;

        for(int h = 0; h < len-1; h++){
            if(citations[h] >= h+1 && citations[h+1] <= h+1) return h+1;
        }

        return (citations[len-1]==0)?0:len;
    }
};
