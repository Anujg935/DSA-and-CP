class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = INT_MIN;
        int curr = 0;
        for(int i = 0;i< nums.size();i++){
            if(nums[i] == 1){
                curr++;
            }
            else
                curr = 0;
            
            res = max(res, curr);
        }
        
        return res;
    }
};