class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto i:nums){
            s.insert(i);
        }
        int ans = 0;
        for(auto i:nums){
            
            if(s.find(i-1) == s.end()){
                int cnt = 0;
                int t= i;
                
                while(s.find(t) !=s.end()){
                    cnt++;
                    t++;
                }
                
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};