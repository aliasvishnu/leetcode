#include <unordered_map>
class Solution {
public:
    unordered_map<int, int> memo;

    int climbStairs(int n) {
        if(n <= 1) return 1;
        if(n == 2) return 2;

        if(memo.find(n-1) == memo.end()){
            memo[n-1] = climbStairs(n-1);
        }
        if(memo.find(n-2) == memo.end()){
            memo[n-2] = climbStairs(n-2);
        }

        memo[n] = memo[n-1] + memo[n-2];
        return memo[n];
    }
};
