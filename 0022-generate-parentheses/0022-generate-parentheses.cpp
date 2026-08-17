class Solution {
public:

    void solve(string current, int open, int close, int n,
               vector<string>& ans) {

        // Base case
        if(current.length() == 2 * n) {
            ans.push_back(current);
            return;
        }

        // We can add '(' if we haven't used all opening brackets
        if(open < n) {
            solve(current + "(", open + 1, close, n, ans);
        }

        // We can add ')' only when there is an unmatched '('
        if(close < open) {
            solve(current + ")", open, close + 1, n, ans);
        }
    }

    vector<string> generateParenthesis(int n) {

        vector<string> ans;

        solve("", 0, 0, n, ans);

        return ans;
    }
};