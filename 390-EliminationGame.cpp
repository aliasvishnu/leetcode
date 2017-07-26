class Solution {
public:

    int lastRemaining(int n) {
        int ltor = 1, pos = 1, step = 1;
        while(n >= 2){
            if(n%2 == 0){
                pos = pos + ltor*step*(n-1);
            }else{
                pos = pos + ltor*step*(n-2);
            }

            ltor *= -1;
            step *= 2;
            n /= 2;
        }

        if(n == 1) return pos;
    }
};
