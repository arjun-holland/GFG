class Solution {
  public:
    int countConsec(int n) {
      //  const int MOD = 1e9 + 7;
    
    // Compute 2^n % MOD
    long long totalStrings = 1;
    for (int i = 0; i < n; ++i) {
        totalStrings = (totalStrings * 2);// % MOD;
    }
    
    // Compute number of binary strings without consecutive 1s
    vector<long long> dp(n + 1, 0);
    dp[0] = 1; // There is 1 way to have a string of length 0 (the empty string)
    dp[1] = 2; // There are 2 ways to have a string of length 1 ("0", "1")

    for (int i = 2; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]);// % MOD;
    }
    
    // Number of binary strings with consecutive 1s
    long long withConsecutiveOnes = (totalStrings - dp[n]);// + MOD) % MOD;
    
    return withConsecutiveOnes;
    }
};