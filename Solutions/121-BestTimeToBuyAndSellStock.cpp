// Time - O(n)
// Space - O(n)
//  Main idea - Keep track of minimum cost till now.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();

        int profit = 0;
        int minValue = INT_MAX;

        for(int i = 0; i < len; i++){
            if(prices[i]-minValue > profit) profit = prices[i] - minValue;
            if(minValue > prices[i]) minValue = prices[i];
        }

        return profit;
    }
};
