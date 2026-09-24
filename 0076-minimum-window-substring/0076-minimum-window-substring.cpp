class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mpp;

        // Store how many of each character we need
        for(char c : t) {
            mpp[c]++;
        }

        int left = 0;
        int count = t.size();

        int minLen = INT_MAX;
        int start = 0;

        for(int right = 0; right < s.size(); right++) {

            // If this character is needed
            if(mpp[s[right]] > 0) {
                count--;
            }

            mpp[s[right]]--;

            // Window contains everything we need
            while(count == 0) {

                // Update minimum window
                if(right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // Remove left character
                mpp[s[left]]++;

                // We are now missing this character
                if(mpp[s[left]] > 0) {
                    count++;
                }

                left++;
            }
        }

        if(minLen == INT_MAX) {
            return "";
        }

        return s.substr(start, minLen);
    }
};