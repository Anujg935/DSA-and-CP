class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt =0;
        if(flowerbed.size()==1){
            if(flowerbed[0] == 0){
                if(n<=1){
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                if(n==0){
                    return true;
                }
                else{
                    return false;
                }
            }
        }
        if(flowerbed[0] == 0 && flowerbed[1] == 0){
            flowerbed[0]=1;
            cnt++;
        }
            
        for(int i=1;i<flowerbed.size()-1;i++){
            if(flowerbed[i] == 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0){
                flowerbed[i] = 1;
                cnt++;
            }
        }
        if(flowerbed[flowerbed.size()-1]==0 && flowerbed[flowerbed.size()-2]==0)
            cnt++;
        if(cnt >= n)
            return true;
        return false;
    }
};