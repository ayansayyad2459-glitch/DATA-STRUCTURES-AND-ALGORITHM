class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
        for(int j= i+1;j<n;j++){
            if(j>i+1 && nums[j]==nums[j-1])continue;
            int k =j+1;
            int l = n-1;
            while(k<l){
                long long sum = nums[i];
                sum+= nums[j];
                sum+= nums[k];
                sum+= nums[l];
                if(sum==target){
                 vector<int>temp{nums[i],nums[j],nums[k],nums[l]};
                 ans.push_back(temp);
                 k++,l--;
                 while(k<l && nums[k]==nums[k-1]) k++;
                 while(k<l && nums[l]==nums[l+1])l--;

                }
                else if(sum>target){
                   l--;
                }
                else{
                 k++;
                }
            }
        }
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         vector<vector<int>> results;
//         int n = nums.size();
        
//         // 1. Sort the array
//         sort(nums.begin(), nums.end());

//         // 2. First fixed pointer
//         for (int i = 0; i < n - 3; i++) {
//             // Skip duplicates for i
//             if (i > 0 && nums[i] == nums[i - 1]) continue;
            
//             // 3. Second fixed pointer
//             for (int j = i + 1; j < n - 2; j++) {
//                 // Skip duplicates for j
//                 if (j > i + 1 && nums[j] == nums[j - 1]) continue;

//                 // 4. Two-pointer setup
//                 int left = j + 1;
//                 int right = n - 1;

//                 while (left < right) {
//                     // Cast to long long to prevent integer overflow
//                     long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

//                     if (sum == target) {
//                         results.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
//                         // Skip duplicates for left and right
//                         while (left < right && nums[left] == nums[left + 1]) left++;
//                         while (left < right && nums[right] == nums[right - 1]) right--;
                        
//                         left++;
//                         right--;
//                     } 
//                     else if (sum < target) {
//                         left++;
//                     } 
//                     else {
//                         right--;
//                     }
//                 }
//             }
//         }
//         return results;
//     }
// };