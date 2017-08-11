class Solution {
public:

    uint32_t reverseBits(uint32_t n) {
        unsigned long ans = 0;
        for(int i = 1; i<= 32; i++){
            ans = (ans << 1) | n%2;
            n /= 2;
        }
        return ans;
    }
};
