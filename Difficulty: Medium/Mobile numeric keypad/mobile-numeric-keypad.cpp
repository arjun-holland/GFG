// class Solution {
//   public:
//     // Adjacency list: defines which digits are reachable from each digit
//     vector<vector<int>> numbers = {
//         {0, 8},         // 0
//         {1, 2, 4},      // 1
//         {2, 1, 3, 5},   // 2
//         {3, 2, 6},      // 3
//         {4, 1, 5, 7},   // 4
//         {5, 2, 4, 6, 8},// 5
//         {6, 3, 5, 9},   // 6
//         {7, 4, 8},      // 7
//         {8, 5, 7, 9, 0},// 8
//         {9, 6, 8}       // 9
//     };

//     // Recursive function: how many sequences of length 'count + 1' can start from 'num'
//     long long solve(int num, int count) {
//         if (count == 0)
//             return 1; // Base case: sequence is complete

//         long long total = 0;
//         for (int next : numbers[num]) {
//             total += solve(next, count - 1);
//         }

//         return total;
//     }

//     // Driver function
//     long long getCount(int N) {
//         long long total = 0;

//         for (int i = 0; i < 10; i++) {
//             total += solve(i, N - 1); // N-1 more steps after starting digit
//         }

//         return total;
//     }
// };




class Solution {
  public:
    // Adjacency list: defines which digits are reachable from each digit
    vector<vector<int>> numbers = {
        {0, 8},         // 0
        {1, 2, 4},      // 1
        {2, 1, 3, 5},   // 2
        {3, 2, 6},      // 3
        {4, 1, 5, 7},   // 4
        {5, 2, 4, 6, 8},// 5
        {6, 3, 5, 9},   // 6
        {7, 4, 8},      // 7
        {8, 5, 7, 9, 0},// 8
        {9, 6, 8}       // 9
    };

    // Recursive function: how many sequences of length 'count + 1' can start from 'num'
    long long solve(int num, int count,vector<vector<int>>& dp) {
        if (count == 0)
            return 1; // Base case: sequence is complete

        if(dp[num][count] != -1)return dp[num][count];
        
        long long total = 0;
        for (int next : numbers[num]) {
            total += solve(next, count - 1, dp);
        }

        return dp[num][count] = total;
    }

    // Driver function
    long long getCount(int N) {  // N : length
        long long total = 0;
        vector<vector<int>> dp(10,vector<int>(N+1,-1));
        for (int i = 0; i < 10; i++) {
            total += solve(i, N - 1, dp); // N-1 more steps after starting digit
        }

        return total;
    }
};
