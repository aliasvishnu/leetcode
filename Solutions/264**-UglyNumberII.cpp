class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> k(n+1, 0);
        k[0] = 1;
        /**
        * 2x1 2x2 2x3 2x4 2x5(t2) 2x6 2x8 2x9
        * 3x1 3x2 3x3(t3) 3x4 3x5 3x6 3x8 3x9
        * 5x1 5x2 5x3(t5) 5x4 5x5 5x6 5x8 5x9 ...
        t2, t3, t5 are scanning through the array
        At any stage, we have to produce next minimum value between k[t2]*2, k[t3]*3, k[t4]*4;

        **/

        int t2 = 0, t3 = 0, t5 = 0;
        for(int i = 1; i <= n; i++){
            k[i] = min(k[t2]*2, min(k[t3]*3, k[t5]*5));

            if(k[i] == k[t2]*2) t2++;
            if(k[i] == k[t3]*3) t3++;
            if(k[i] == k[t5]*5) t5++;
        }
        return k[n-1];
    }
};
