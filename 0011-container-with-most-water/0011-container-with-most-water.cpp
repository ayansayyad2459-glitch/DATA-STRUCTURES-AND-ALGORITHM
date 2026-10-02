class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxwater = 0;
        int width = 0;
        int lp=0;
        int rp= height.size()-1;
        while(lp<rp){
            width = rp-lp;
            int ht = min(height[lp],height[rp]);
            int currentwater = width*ht;
            maxwater = max(currentwater,maxwater);
            if(height[lp]<height[rp]){
                lp++;
            }
            else{
                rp--;
            }
        }
        return maxwater;
    }
};