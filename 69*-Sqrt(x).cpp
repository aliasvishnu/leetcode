class Solution {
public:
  int mySqrt(int x) {
        int answer = 0, start = 1, end = x;
        if(x == 0) return 0;

        while(start <= end){
            int mid = start + (end-start)/2;
            if(x*1.0/mid < mid) end = mid-1;
            else{
                start = mid+1;
                answer = mid;
            }
        }
        return answer;
    }
};
