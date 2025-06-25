class Solution {
public:
    string maxSubseq(string& s, int k) {
        int n = s.size();
        int keep = n - k;
        stack<char> st;

        for (char c : s) {
            while (!st.empty() && st.top() < c && k > 0) {
                st.pop();
                k--;
            }

            if ((int)st.size() < keep) {
                st.push(c);
            } else {
                k--;  // remove this char from consideration
            }
        }

        // Build result string from stack
        string ans(keep, ' ');
        for (int i = keep - 1; i >= 0; --i) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};
