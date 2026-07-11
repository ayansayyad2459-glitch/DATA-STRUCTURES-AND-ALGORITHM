class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();
        // counting frequency
        unordered_map<int, int> mpp;
        for(int i=0;i<n;i++){
            mpp[arr[i]]++;
        }
        // checking lucky integars
        int ans = -1;
        for(auto it : mpp){
            if(it.first == it.second){
                ans = max(ans,it.first);
            }
        }
        return ans;
    }
};