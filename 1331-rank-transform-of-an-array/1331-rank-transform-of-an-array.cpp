class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>temp = arr;
        sort(temp.begin(),temp.end());
        unordered_map<int, int>mpp;
        int rank = 1;
        // mapping the rank
        for(int i=0;i<temp.size();i++){
          if(mpp.find(temp[i])==mpp.end()){
              mpp[temp[i]]= rank;
          rank++;
           }
        }
        // replacing the array with their rank
        for(int i = 0;i<arr.size();i++){
            arr[i]= mpp[arr[i]];
        }
        return arr;
    }
};