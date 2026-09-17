class Solution {
public:

    // Count subarrays with sum <= goal
    int atMost(vector<int>& nums, int goal) {
        if(goal < 0) return 0;

        int left = 0;
        int sum = 0;
        int count = 0;

        for(int right = 0; right < nums.size(); right++) {

            // Add current element
            sum += nums[right];

            // Shrink if sum becomes too large
            while(sum > goal) {
                sum -= nums[left];
                left++;
            }

            // All subarrays ending at right are valid
            count += right - left + 1;
        }

        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {

        // Exactly goal = atMost(goal) - atMost(goal - 1)
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};