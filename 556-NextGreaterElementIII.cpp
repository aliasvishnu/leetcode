class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> vec(10, 0);
        int start = 10;
        for(int i = 9; i >= 0; i--){
            if(n > 0) start-=1;
            vec[i] = n%10;
            n /= 10;
        }
        int descending = 1, loc = -1;
        for(int i = start; i < 9; i++){
            if(vec[i+1] > vec[i]){
                descending = 0;
                loc = i;
            }
        }

        if(descending) return -1;

        int newLoc = loc+1;
        for(int i = loc+1; i < 10; i++){
            if(vec[i] > vec[loc] && vec[i] < vec[newLoc]) newLoc = i;
        }

        int temp = vec[loc];
        vec[loc] = vec[newLoc];
        vec[newLoc] = temp;

        sort(vec.begin()+loc+1, vec.end());

        long ans = 0;
        for(int i = start; i < 10; i++){
            ans = ans*10+vec[i];
        }

        if(ans > INT_MAX) return -1;
        else return ans;
    }
};
