class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;

        long num = x, a = 0, b = 0;
        while(num != 0){
            a = a*10+num%10;
            num /= 10;
        }

        return (x == a);
    }
};
