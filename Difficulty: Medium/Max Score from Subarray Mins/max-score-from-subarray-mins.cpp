// class Solution {
//   public:
//     int maxSum(vector<int> &arr) {
//         int n = arr.size();
//         int maxScore = 0;

//         for (int i = 0; i < n; ++i) {
//             int min1 = INT_MAX, min2 = INT_MAX;
//             for (int j = i; j < n; ++j) {
//                 if (arr[j] < min1) {
//                     min2 = min1;
//                     min1 = arr[j];
//                 } else if (arr[j] < min2) {
//                     min2 = arr[j];
//                 }
//                 if (j - i + 1 >= 2) {
//                     maxScore = max(maxScore, min1 + min2);
//                 }
//             }
//         }

//         return maxScore;
//     }
// };
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int maxSum(vector<int>& arr) {
        stack<int> s;
        int maxSum = 0;

        for (int i = 0; i < arr.size(); ++i) {
            while (!s.empty() && s.top() >= arr[i]) {
                s.pop(); // maintain increasing stack
            }
            if (!s.empty()) {
                maxSum = max(maxSum, s.top() + arr[i]); // candidate pair
            }
            s.push(arr[i]);
        }

        // Also consider adjacent pairs directly
        for (int i = 0; i < arr.size() - 1; ++i) {
            maxSum = max(maxSum, arr[i] + arr[i + 1]);
        }

        return maxSum;
    }
};
