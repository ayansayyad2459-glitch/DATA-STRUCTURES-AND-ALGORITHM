class Solution {
public:

    int atMost(vector<int>& nums, int k) {
        if(k == 0) return 0;

        unordered_map<int, int> mpp;

        int left = 0;
        int ans = 0;

        for(int right = 0; right < nums.size(); right++) {

            // Add current number
            mpp[nums[right]]++;

            // More than k different numbers
            while(mpp.size() > k) {

                mpp[nums[left]]--;

                // Remove number completely
                if(mpp[nums[left]] == 0) {
                    mpp.erase(nums[left]);
                }

                left++;
            }

            // Count valid subarrays ending at right
            ans += right - left + 1;
        }

        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {

        // Exactly k = At most k - At most (k-1)
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};