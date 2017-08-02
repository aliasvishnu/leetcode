class Solution {
public:
    bool isPrime(int num){
        int lim = sqrt(num);
        for(int i = 2; i <= lim; i++){
            if(num%i == 0) return false;
        }
        return true;
    }

    bool check(int num){
        if(isPrime(num) && num > 5) return false;

        for(int i = 6; i <= num/2; i++){
            if(num%i == 0 && isPrime(i)) return false;
        }
        return true;
    }

    bool isUgly(int num) {
        if(num == 1) return true;
        if(num <= 0) return false;
        while(num%2 == 0) num/=2;
        while(num%3 == 0) num/=3;
        while(num%5 == 0) num/=5;

        return check(num);

    }
};
