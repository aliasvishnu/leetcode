// Time - O(n), Space - O(n)
// Similar to Problem 31 - Next permutation.

class Solution {
public:
    int maximumSwap(int num) {
        vector<int> vec;

        while(num != 0){
            vec.push_back(num%10);
            num/=10;
        }

        int len = vec.size();
        reverse(vec.begin(), vec.end());

        vector<pair<int, int>> right(len, make_pair(0, len-1));
        pair<int, int> largest = make_pair(0, len-1);
        for(int i = len-1; i >= 0; i--){
            right[i] = largest;
            if(vec[i] > largest.first) largest = make_pair(vec[i], i);
        }

        for(int i = 0; i < len-1; i++){
            if(right[i].first > vec[i]){
                swap(vec[i], vec[right[i].second]);
                break;
            }
        }

        int n = 0;
        for(int i = 0; i < len; i++){
            n = n*10+vec[i];
        }

        return n;

    }
};
