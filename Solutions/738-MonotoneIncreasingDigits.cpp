class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        vector<int> n;

        while(N != 0){
            n.push_back(N%10);
            N /= 10;
        }

        reverse(n.begin(), n.end());

        long answer = 0, len = n.size();
        for(int i = 0; i < len-1; i++){
            if(n[i] > n[i+1]){
                int j = i;
                while(n[j] == n[i]) j--;
                j++;
                n[j++] -= 1;

                for(; j < len; j++) n[j] = 9;
                break;
            }
        }

        for(int i = 0; i < len; i++) answer = answer*10+n[i];
        return answer;
    }
};
