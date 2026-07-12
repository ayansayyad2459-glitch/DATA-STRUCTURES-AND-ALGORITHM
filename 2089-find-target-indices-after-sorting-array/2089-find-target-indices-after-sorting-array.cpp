class Solution {
public:
    // optimal way without sorting
    vector<int> targetIndices(vector<int>& nums, int target) {
        int smaller = 0;
        int equal = 0;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<target){
                smaller++;
            }
            else if(nums[i]==target){
                equal++;
            }
        }
        for(int i=0;i<equal;i++){
            ans.push_back(smaller + i);
        }
        return ans;
    }
};

// // class Solution {
// public:
//     vector<int> targetIndices(vector<int>& nums, int target) {
//         vector<int>ans;
//         sort(nums.begin(),nums.end());
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]==target){
//                 ans.push_back(i);
//             }
//         }
//         return ans;
//     }
// };