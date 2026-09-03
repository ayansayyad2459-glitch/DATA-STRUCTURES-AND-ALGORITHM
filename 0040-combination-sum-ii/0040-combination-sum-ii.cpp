class Solution {
public:

    void solve(int start, int target,
               vector<int>& candidates,
               vector<int>& ds,
               vector<vector<int>>& ans) {

        if(target == 0) {
            ans.push_back(ds);
            return;
        }

        for(int i = start; i < candidates.size(); i++) {

            // Skip duplicate values at the same recursion level
            if(i > start && candidates[i] == candidates[i-1])
                continue;

            // Since sorted, no point going further
            if(candidates[i] > target)
                break;

            // Take
            ds.push_back(candidates[i]);

            // i + 1 because we can use each element only once
            solve(i + 1, target - candidates[i],
                  candidates, ds, ans);

            // Backtrack
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates,
                                         int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> ds;

        solve(0, target, candidates, ds, ans);

        return ans;
    }
};