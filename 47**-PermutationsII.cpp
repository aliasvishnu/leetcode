class Solution {
public:


    vector<vector<int>> result;

    void recursion(vector<int> num, int start, int len){
        if(start == len-1){
            result.push_back(num);
            return;
        }

        for(int i = start; i < len; i++){
            if(i != start && num[start] == num[i]) continue;
            swap(num[start], num[i]);
            recursion(num, start+1, len);
        }


    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        recursion(nums, 0, nums.size());
        return result;
    }
};
