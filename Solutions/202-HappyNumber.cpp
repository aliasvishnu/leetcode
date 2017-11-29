class Solution {
public:
    long splitSquare(int n){
        int sum = 0;
        while(n != 0){
            sum += pow(n%10, 2);
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> st;
        st.insert(n);
        while(true){
            if(n == 1) return true;
            n = splitSquare(n);
            if(st.find(n) != st.end()) return false;
            else st.insert(n);
        }
    }
};
