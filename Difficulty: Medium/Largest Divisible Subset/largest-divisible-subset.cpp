class Solution {
public:
    vector<int> largestSubset(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        vector<vector<int>> dp(n);

        vector<int> result;

        for (int i = 0; i < n; i++) {
            dp[i].push_back(arr[i]);

            for (int j = 0; j < i; j++) {
                bool valid = true;

                // Check if arr[i] is divisible with every element in dp[j]
                for (int x : dp[j]) {
                    if (arr[i] % x != 0 && x % arr[i] != 0) {
                        valid = false;
                        break;
                    }
                }

                if (valid && dp[j].size() + 1 > dp[i].size()) {
                    dp[i] = dp[j];
                    dp[i].push_back(arr[i]);
                } else if (valid && dp[j].size() + 1 == dp[i].size()) {
                    vector<int> temp = dp[j];
                    temp.push_back(arr[i]);
                    if (temp > dp[i]) {
                        dp[i] = temp;
                    }
                }
            }

            if (dp[i].size() > result.size() || (dp[i].size() == result.size() && dp[i] > result)) {
                result = dp[i];
            }
        }

        return result;
    }
};
