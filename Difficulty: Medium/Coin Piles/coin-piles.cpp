class Solution {
public:
    int minimumCoins(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<long long> prefix(n + 1, 0);
        
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + arr[i]; // prefix sum
        }

        long long res = LLONG_MAX;

        for (int i = 0; i < n; ++i) {
            // arr[i] is the smallest allowed value in final pile
            int maxAllowed = arr[i] + k; //limit 

            // Use binary search to find first pile > maxAllowed
            int idx = upper_bound(arr.begin(), arr.end(), maxAllowed) - arr.begin();

            // Coins to remove:
            // - From 0 to i-1: remove entire piles
            // - From idx to n-1: remove extra coins beyond maxAllowed

            long long removeLeft = prefix[i]; // Remove all coins from left part
            long long removeRight = prefix[n] - prefix[idx] - 1LL * (n - idx) * maxAllowed;

            long long totalRemove = removeLeft + removeRight;
            res = min(res, totalRemove);
        }

        return (int)res;
    }
};
