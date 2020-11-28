class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b = INT_MAX;
        int m = 0;
        for(int i=0;i<prices.size();i++){
            if(prices[i] < b){
                b = prices[i];
            }
            else if((prices[i] - b) > m){
                m = (prices[i] - b);
            }
        }
        return m;
    }
};