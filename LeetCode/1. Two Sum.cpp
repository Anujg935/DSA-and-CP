class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans ;
        unordered_map<int, int> um;
        
        
        for(int i=0;i<nums.size();i++){
            if(um.find(target-nums[i]) != um.end()){
                ans.push_back(um[target-nums[i]]);
                ans.push_back(i);
                return ans;
            }
            um[nums[i]] = i;
        }
        return ans;
    }
};