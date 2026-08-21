class Solution {

public: 
     void findcombinationsum(int index, int target,vector<int>&arr, vector<vector<int>>&ans, vector<int>&ds){
        if(index==arr.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }

        // pick up the element
        if(arr[index]<= target){
            ds.push_back(arr[index]);
            findcombinationsum(index,target- arr[index], arr,ans,ds);
            ds.pop_back();
        }
        findcombinationsum(index+1,target,arr,ans,ds);
     }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        findcombinationsum(0,target,candidates,ans,ds);
        return ans;
    }
};