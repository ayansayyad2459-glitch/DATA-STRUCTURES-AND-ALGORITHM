class Solution {
public:
    void merge(vector<int>& nums,int low, int mid, int high){
        // storing element in a temporary array
        vector<int>temp;
        int left = low;
        int right = mid+1;
        while( left<=mid && right<= high){
            if(nums[left]<= nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }
            // if elements are still remaining on the left side
            while(left<=mid){
                temp.push_back(nums[left]);
                left++;
            }
            while(right<=high){
                temp.push_back(nums[right]);
                right++;
            }
            // transfering temporary elements in the array
            for(int i=low;i<=high;i++){
                nums[i]= temp[i-low];   
                // // temp starts from 0, arr starts from low
               // temp[i-low] converts arr index -> temp index
            }
    }

    // now counting pairs 
   int countPairs(vector<int> & nums, int low, int mid, int high){
    int right = mid +1 ;
    int count = 0;
    for(int i = low;i<=mid;i++){
        while(right<=high && nums[i]> 2LL*nums[right]){
            right++;
        
        }
            count += (right-(mid+1));
    }
    return count;
   }
//  sorting the array
   int mergeSort(vector<int> &nums, int low, int high) {
    int count = 0;
    if (low >= high) return count;      
    //  its a base case
    int mid = (low + high) / 2 ;
    count += mergeSort(nums, low, mid);  // left half
    count += mergeSort(nums, mid + 1, high); // right half
    count += countPairs(nums, low, mid, high); //Modification
    merge(nums, low, mid, high);  // merging sorted halves
    return count;
}
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        {
    return mergeSort(nums, 0, n - 1);
}
    }
};