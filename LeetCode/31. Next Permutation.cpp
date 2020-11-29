class Solution {
public:
    
    void nextPermutation(vector<int>& nums) {
        int n= nums.size();
        if(n <=1){
            return;
        }
        int i = n-2;
        while(i>=0 && nums[i] >= nums[i+1]){
            i--;
        }
        if(i < 0){
            reverse(nums.begin(), nums.end());
            return;
        }
        else{
            int idx1 = i;
            int j = n-1;
            while(j>idx1){
                if(nums[j] > nums[idx1]){
                    break;
                }
                j--;
            }
            int idx2 = j;
            swap(nums[idx1], nums[idx2]);
            reverse(nums.begin()+ idx1 +1, nums.end());
            
        }
        
    }
};