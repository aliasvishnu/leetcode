class Solution {
public:
    double myPow(double x, long n) {
        if(n == 0) return 1;
        if(n == 1) return x;
        if(n < 0) return myPow(1.0/x, -1*n);

        double ans = 1;
        if(n%2 == 1) ans = x;
        double temp = myPow(x, n/2);
        return temp*temp*ans;
    }
};
