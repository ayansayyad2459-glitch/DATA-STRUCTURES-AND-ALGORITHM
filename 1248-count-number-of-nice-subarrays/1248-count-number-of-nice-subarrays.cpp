class Solution {
public:
    int countodds(vector<int>& nums, int k){
        int left=0;
        int countodds =0 ;
        int ans = 0;
        for(int right = 0;right<nums.size();right++){
            if(nums[right]%2 !=0){
                countodds++;
            }
            while(countodds>k){
                 if(nums[left] % 2 != 0) {
                    countodds--;
                }
                left = left+1;
            }
            ans = ans+ (right-left+1);
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        return countodds(nums,k)- countodds(nums,k-1);
    }
};