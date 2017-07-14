#include <math.h>
class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0; long divisor = 5;
        while(n >= divisor){
            count += n/divisor;
            divisor *= 5;
        }
        return count;
    }
};
