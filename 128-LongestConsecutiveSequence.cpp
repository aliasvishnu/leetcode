#include <unordered_map>
class Solution {
public:

    unordered_map<int, bool> visit;
    unordered_map<int, int> L;
    int maxVal = 1;

    void f(int num){
        cout << "Visiting " << num << endl;
        int prev = num-L[num];
        if(L.find(prev) != L.end()){
            if(visit[prev] == false){
                f(prev);
                visit[prev] = true;
            }

            L[num] = L[prev] + num-prev;
            cout << "L[" << num << "]=" << L[num] << endl;
            if(L[num] > maxVal) maxVal = L[num];
        }
    }

    int longestConsecutive(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;

        for(int i = 0; i < len; i++){
            L[nums[i]] = 1;
            visit[nums[i]] = false;
        }


        for(int i = 0; i < len; i++){
            if(visit[nums[i]] == false){
                f(nums[i]);
                visit[nums[i]] = true;
            }
        }

        return maxVal;
    }
};
