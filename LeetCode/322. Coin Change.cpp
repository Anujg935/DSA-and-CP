class Solution {
public:
    int coinChange(vector<int> &coins, int amount, int *dp){
        if(amount<0)
            return -1;
        
        if(amount == 0){
            return 0;
        }
        
        if(dp[amount] !=-1)
            return dp[amount];
        int ans = INT_MAX;
        
        for(int i=0;i<coins.size();i++){
                int curr = 0;
                curr= coinChange(coins, amount-coins[i], dp);
                if(curr >=0 && curr<INT_MAX )
                    ans = min(ans, curr+1);
        }
        return dp[amount] = (ans==INT_MAX) ? INT_MAX:ans;
        
            
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        int *dp = new int[amount+5];
        
        for(int i=0;i<=amount;i++){
            dp[i] = -1;
        }
        int res = coinChange(coins, amount, dp);
        if(res==INT_MAX)
            return -1;
        return res;
    }
};#include <iostream>
using namespace std;
int main() {
    cout<<"Hello World!";
}
