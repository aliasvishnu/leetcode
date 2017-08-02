class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> k(n+1, 0);

        k[0] = 1;
        int lenp = primes.size();
        vector<int> t(lenp, 0);

        for(int i = 1; i <= n; i++){
            int minval = INT_MAX;
            for(int j = 0; j < lenp; j++){
                if(k[t[j]]*primes[j] < minval) minval = k[t[j]]*primes[j];
            }

            k[i] = minval;
            for(int j = 0; j < lenp; j++){
                if(k[t[j]]*primes[j] == minval) t[j]++;
            }
        }

        return k[n-1];
    }
};
