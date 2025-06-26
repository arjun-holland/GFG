class Solution {
  public:
    int minValue(string &s, int k) {
        unordered_map<char,int> freq;
        for (char c : s) freq[c]++;

        priority_queue<int> maxHeap;
        for (auto it=freq.begin(); it != freq.end();it++) {
            maxHeap.push(it->second);
        }

        // Remove k characters
        while (k-- && !maxHeap.empty()) {
            int top = maxHeap.top();
            maxHeap.pop();
            top--;
            if (top > 0) maxHeap.push(top);
        }

        int ans = 0;
        while (!maxHeap.empty()) {
            int f = maxHeap.top();
            maxHeap.pop();
            ans += f * f;
        }

        return ans;
    }
};
