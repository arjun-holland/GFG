class Solution {
public:
    int longestCommonSum(vector<int> &a1, vector<int> &a2) {
        int n = a1.size();
        vector<int> diff(n);
        
        // Step 1: Compute the difference array
        for (int i = 0; i < n; ++i) {
            diff[i] = a1[i] - a2[i];
        }

        // Step 2: Find the longest subarray with sum = 0
        unordered_map<int, int> sumIndex;
        int maxLen = 0, prefixSum = 0;

        for (int i = 0; i < n; ++i) {
            prefixSum += diff[i];

            if (prefixSum == 0) {
                maxLen = i + 1;
            }
            if (sumIndex.find(prefixSum) != sumIndex.end()) {
                maxLen = max(maxLen, i - sumIndex[prefixSum]);
            } else {
                sumIndex[prefixSum] = i;
            }
        }

        return maxLen;
    }
};
