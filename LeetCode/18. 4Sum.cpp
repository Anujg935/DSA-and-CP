class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        set<int> s;
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int left = j+1, right= n-1;
                while(left<right){
                    int sum = nums[i]+nums[j]+nums[left]+ nums[right];
                    if(sum == target){
                        vector<int> curr = {nums[i], nums[j], nums[left], nums[right]};
                        ans.push_back(curr);
                        left++;
                        right--;
                        while(left < right && nums[left]==curr[2])
                            left++;
                        
                        while(left < right && nums[right]==curr[3])
                            right--;
                        
                    }
                    else if(sum > target)
                        right--;
                    else
                        left++;
                }
                while(j+1 < n && nums[j+1] == nums[j]) j++;
                
            }
            while(i+1 < n && nums[i+1] == nums[i]) i++;
        }
        
        return ans;
    }
};