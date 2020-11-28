class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows ==0){
            return res;
        }
        
        for(int i=1;i<=numRows;i++){
            vector<int> c;
            for(int j=0;j<i;j++){
                if(j==0 || j ==i-1){
                    c.push_back(1);
                }
                else{
                    c.push_back(res[i-2][j-1]+res[i-2][j]);
                }
            }
            res.push_back(c);
        }
        return res;
    }
};