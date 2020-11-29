class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int nums1 = -1, nums2 = -1, cnt1 = 0, cnt2 = 0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i] == nums1){
                cnt1++;
            }
            else if( nums[i] == nums2){
                cnt2++;
            }
            else if(cnt1==0){
                nums1 = nums[i];
                cnt1++;
            }
            else if(cnt2==0){
                nums2 = nums[i];
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        
        vector<int> res;
        cnt1 = 0;cnt2 = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == nums1)
                cnt1++;
            else if(nums[i] == nums2)
                cnt2++;
        }
        if(cnt1 > nums.size()/3)
            res.push_back(nums1);
        if(cnt2 > nums.size()/3)
            res.push_back(nums2);
        return res;
    }
};