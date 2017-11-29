class Solution {
public:
    string convertToTitle(int n) {
        return (n == 0)? "":convertToTitle((n-1)/26) + string(1, ((n-1)%26+'A'));
    }
};
