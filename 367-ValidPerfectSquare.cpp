class Solution {
public:
    bool isPerfectSquare(int num) {
        int i = 0;
        if (num == 0) return true;

        else{
            int val = 1;
            int sum = 0;
            while(sum <= num){
                if(sum+val == num) return true;
                else if(sum+val < 0) break;
                else{
                    sum += val;
                    val += 2;
                }
            }

        }
        return false;
    }
};
