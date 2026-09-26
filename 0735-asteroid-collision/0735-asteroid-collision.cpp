class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        list<int> st;

        for(int i = 0; i < asteroids.size(); i++) {

            int curr = asteroids[i];
            bool destroyed = false;

            // Collision: positive on left, negative on right
            while(!st.empty() && st.back() > 0 && curr < 0) {

                if(st.back() < -curr) {
                    // Stack asteroid is smaller
                    st.pop_back();
                }
                else if(st.back() == -curr) {
                    // Both are destroyed
                    st.pop_back();
                    destroyed = true;
                    break;
                }
                else {
                    // Current asteroid is smaller
                    destroyed = true;
                    break;
                }
            }

            // Current asteroid survived
            if(!destroyed) {
                st.push_back(curr);
            }
        }

        // Convert list to vector
        return vector<int>(st.begin(), st.end());
    }
};