class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        vector<int> ans;
        sort(a.rbegin(),a.rend());
        sort(b.rbegin(),b.rend());
        int i=0;
        priority_queue<pair<int,pair<int,int>>> pq;
        set<pair<int,int>> st;
        pq.push({a[0]+b[0],{0,0}});
        st.insert({0,0});

        while(i < k && !pq.empty()){
            auto tp = pq.top();
            pq.pop();
            int sum = tp.first;
            int l = tp.second.first;
            int r = tp.second.second;
            ans.push_back(sum);
            if(l+1 < n && st.find({l+1,r}) == st.end()){
                pq.push({{a[l+1]+b[r]},{l+1,r}});
                st.insert({l+1,r});
            }
            if(r+1 < n && st.find({l,r+1}) == st.end()){
                pq.push({a[l]+b[r+1],{l,r+1}});
                st.insert({l,r+1});
            }
            i++;
        }
        return ans;
    }
};