#include <bits/stdc++.h>
class Solution {

    private:
      int firstposition(vector<int> &nums,int target){
        int low=0;
        int high = nums.size()-1;
        int firstpos = -1;
        while(low<=high){
            int mid = low + (high - low) / 2;
            if(nums[mid]>=target){
                if(nums[mid]==target){
                firstpos = mid;
                }
                high = mid-1;
                }
             else{
                low = mid+1;
            }
        }
        return firstpos;
      }
       int lastposition(vector<int> &nums,int target){
        int low=0;
        int high = nums.size()-1;
        int lastpos = -1;
        while(low<=high){
            int mid = low + (high - low) / 2;
            if(nums[mid]==target){
                lastpos = mid;
                low = mid+1;
            }
            else if(nums[mid]<target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return lastpos;
      }
      
      public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()){
            return {-1,-1};
        }
        int first = firstposition(nums,target);
        int last = lastposition(nums,target);

        return {first, last};
    }
};


// // #include <iostream>
// #include <vector>

// class Solution {
// private:
//     int findFirstPosition(const std::vector<int>& nums, int target) {
//         int lo = 0;
//         int hi = nums.size() - 1;
//         int firstPos = -1;

//         while (lo <= hi) {
//             int mid = lo + (hi - lo) / 2;

//             if (nums[mid] >= target) {
//                 if (nums[mid] == target) {
//                     firstPos = mid;
//                 }
//                 hi = mid - 1;
//             } else {
//                 lo = mid + 1;
//             }
//         }
//         return firstPos;
//     }

//     int findLastPosition(const std::vector<int>& nums, int target) {
//         int lo = 0;
//         int hi = nums.size() - 1;
//         int lastPos = -1;

//         while (lo <= hi) {
//             int mid = lo + (hi - lo) / 2;

//             if (nums[mid] <= target) {
//                 if (nums[mid] == target) {
//                     lastPos = mid;
//                 }
//                 lo = mid + 1;
//             } else {
//                 hi = mid - 1;
//             }
//         }
//         return lastPos;
//     }

// public:
//     std::vector<int> searchRange(std::vector<int>& nums, int target) {
//         if (nums.empty()) {
//             return {-1, -1};
//         }

//         int first = findFirstPosition(nums, target);
//         int last = findLastPosition(nums, target);

//         return {first, last};
//     }
// };

