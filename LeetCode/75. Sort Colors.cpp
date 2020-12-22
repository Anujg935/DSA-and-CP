class Solution {
public:
    void swap(vector<int> & nums, int i, int j){
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
        return;
    }
    void sortColors(vector<int>& nums) {
        
        int low =0, high = nums.size()-1, mid =0;
        
        while(mid<=high){
            if(nums[mid]==1){
                mid++;
            }
            else if(nums[mid]==2){
                swap(nums, mid, high);
                high--;
            }
            else{
                swap(nums, low, mid);
                low++;mid++;
            }
        }
    }
};