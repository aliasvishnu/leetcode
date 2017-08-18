class Solution {
public:
    int maxProduct(vector<int>& A) {
        int imax = A[0];
        int imin = A[0];
        int len = A.size();
        int ans = imax;
        for(int i = 1; i < len; i++){
            if(A[i] < 0){
                int temp = imax;
                imax = imin;
                imin = temp;
            }

            imax = (A[i] > imax*A[i])? A[i]: imax*A[i];
            imin = (A[i] < imin*A[i])?A[i]: imin*A[i];

            ans = (ans > imax)? ans:imax;
        }
        return ans;
    }
};
