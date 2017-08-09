class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int len = A.size();
        if(len == 0) return 0;

        long sum = 0, maxVal = INT_MIN, sumtillnow = 0;
        for(int i = 0; i < len; i++){
            sum += i*A[i];
            sumtillnow += A[i];
        }

        if(maxVal < sum) maxVal = sum;

        for(int i = 1; i < len; i++){
            sum = sum - sumtillnow + len*A[i-1];
            if(sum > maxVal) maxVal = sum;
        }

        return maxVal;
    }
};
