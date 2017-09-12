class Solution {
public:
    int hammingDistance(int x, int y) {
        int sum = 0;
        for (int i = 0; i < 32; i++){
            sum += (x%2 != y%2);
            x >>= 1;
            y >>= 1;
        }
        return sum;
    }
};
