class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n; i++){
            // Skip duplicates for 'i'
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int j = i + 1, k = n - 1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                
                if(sum > 0){
                    k--;
                }
                else if(sum < 0){  // FIX 1: Added the missing condition
                    j++;
                }
                else{
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    
                    // FIX 2: Skip duplicates for 'j' and 'k' to avoid duplicate triplets in 'ans'
                    while(j < k && nums[j] == nums[j-1]) j++;
                    while(j < k && nums[k] == nums[k+1]) k--;
                }
            }
        }
        
        return ans; // FIX 3: Added the return statement
    }
};