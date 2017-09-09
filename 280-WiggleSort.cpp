class Solution {
public:
    void wiggleSort(vector<int>& nums) {
//        *** O(nlogn)  solution commented
//         sort(nums.begin(), nums.end());
//         int len = nums.size(), i = 0;

//         while(i < len){
//             if(i%2 && i+1 < len) swap(nums[i], nums[i+1]);
//             i++;
//         }


        // O(n) solution
        int len = nums.size(), i = 1;
        while(i < len){
            if((i%2 && nums[i-1] > nums[i]) || (i%2 == 0 && (nums[i-1] < nums[i]))) swap(nums[i-1], nums[i]);
            i++;
        }
    }
};
