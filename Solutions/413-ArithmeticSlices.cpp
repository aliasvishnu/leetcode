class Solution {
public:

    // n = number of values sequences are different for, 1, 2, 3, 4, 5 becomes 1, 1, 1, 1 i.e. n = 4.
    int f(int n){
        return (n*n+n)/2;
    }

    int numberOfArithmeticSlices(vector<int>& A) {
        int len = A.size();
        if(len <= 2) return 0;


        int curdiff = A[1] - A[0], curcount = 0, answer = 0;

        for(int i = 2; i < len; i++){
            if(A[i]-A[i-1] == curdiff) curcount += 1;
            else{
                answer += f(curcount);
                curcount = 0;
                curdiff = A[i]-A[i-1];
            }

        }

        answer += f(curcount);


        return answer;
    }
};
