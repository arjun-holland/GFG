class Solution {
public:
    int solve(vector<vector<int>>& m, int r, int c, vector<vector<int>>& dp) {
        int n = m.size();
        int cols = m[0].size();

        // Out of bounds
        if (r < 0 || r >= n || c < 0 || c >= cols)
            return 0;

        // If already computed
        if (dp[r][c] != -1)
            return dp[r][c];

        // If in the last column, just return the gold at that cell
        if (c == cols - 1)
            return dp[r][c] = m[r][c];

        // Explore three directions
        int s1 = m[r][c] + solve(m, r - 1, c + 1, dp); // right-up
        int s2 = m[r][c] + solve(m, r, c + 1, dp);     // right
        int s3 = m[r][c] + solve(m, r + 1, c + 1, dp); // right-down

        return dp[r][c] = max({s1, s2, s3});
    }

    int maxGold(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;

        // Initialize dp table with -1
        vector<vector<int>> dp(n, vector<int>(m, -1));

        // Try starting from every row in the first column
        for (int i = 0; i < n; i++) {
            ans = max(ans, solve(mat, i, 0, dp));
        }
        return ans;
    }
};
