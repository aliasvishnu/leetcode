class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> answer;
        int len1 = findNums.size();

        for(int i = 0; i < len1; i++){
            vector<int> :: iterator it = find(nums.begin(), nums.end(), findNums[i]);
            bool set = false;
            if(it != nums.end()){
                while(it != nums.end()){
                    if(*it > findNums[i]){
                        answer.push_back(*it);
                        set = true;
                        break;
                    }
                    it += 1;
                }
                if(set == false) answer.push_back(-1);
            }
        }
        return answer;
    }
};
