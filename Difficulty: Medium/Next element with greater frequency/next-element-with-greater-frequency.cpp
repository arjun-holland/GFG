class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n, -1);
        unordered_map<int, int> freq;

        for (int x : arr) {
            freq[x]++;
        }

        stack<int> st;                                           // will hold indices

        for (int i = n - 1; i >= 0; i--) {
            // Pop elements from stack while frequency at stack top is <= current
            while (!st.empty() && freq[arr[st.top()]] <= freq[arr[i]]) {
                st.pop();
            }

            // If stack is not empty, top is the next greater frequency element
            if (!st.empty()) {
                result[i] = arr[st.top()];
            }

            // Push current index to stack
            st.push(i);
        }

        return result;
    }
};