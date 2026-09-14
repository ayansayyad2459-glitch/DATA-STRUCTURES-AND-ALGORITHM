class Solution {
public:
    int characterReplacement(string s, int k) {
        int freq[26] = {0};

        int left = 0;
        int maxFreq = 0;
        int ans = 0;

        for(int right = 0; right < s.size(); right++) {

            // Count current character
            freq[s[right] - 'A']++;

            // Highest frequency in current window
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            // Characters that need to be replaced > k
            while((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            // Current valid window
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};