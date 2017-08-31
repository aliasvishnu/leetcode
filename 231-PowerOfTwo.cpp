class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0) return false;

        for(int i = 0; i < 31; i++){
            if((n | 1<<i) == 1<<i) return true;
        }
        return false;
    }
};
