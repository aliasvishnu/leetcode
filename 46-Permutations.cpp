class Solution {
public:

    vector<vector<int>> answer;

    void getPermutations(int index, int len, vector<int>& nums){
        vector<int> temp;
        if(index == len-1){
            temp.push_back(nums[index]);
            answer.push_back(temp);
            return;
        }

        getPermutations(index+1, len, nums);

        int numPerm = answer.size();
        vector<vector<int>> tempanswer;

        for(int i = 0; i < numPerm; i++){
            for(int j = 0; j <= answer[i].size(); j++){
                vector<int> k(answer[i]);
                k.insert(k.begin()+j, nums[index]);
                tempanswer.push_back(k);
            }
        }

        tempanswer.swap(answer);

    }

    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() == 0){
            vector<int> empty;
            answer.push_back(empty);
            return answer;
        }
        else getPermutations(0, nums.size(), nums);
        return answer;
    }
};
