class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        int loc = 1, prev = 0, count = 1, l = 1;

        if(len == 0) return 0;

        prev = nums[0];

        for(int i = 1; i < len; i++){
            // cout << nums[i] << " ";
            if(nums[i] != prev){
                // cout << "Location1" << endl;
                count = 1;
                prev = nums[i];
                nums[loc++] = nums[i];
                l++;
            }else if(count <= 1){
                // cout << "Location2" << endl;
                nums[loc++] = nums[i];
                count++;
            }
        }
        cout << loc;

        return loc;
    }
};
