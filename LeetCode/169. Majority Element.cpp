class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element;
        int i = 0, cnt = 0;
        while(i<nums.size()){
            if(cnt ==0){
                element = nums[i];
            }
            if(element  == nums[i]){
                cnt++;
            }
            else{
                cnt--;
            }
            i++;
        }
        return element;
    }
};