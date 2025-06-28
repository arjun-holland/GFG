class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        // code here
        sort(b.begin(),b.end());
        vector<int> ans;
        for(int e : a){
            int i = upper_bound(b.begin(),b.end(),e)-b.begin();
            //int d = (i-1);
            ans.push_back(i);
        }
        return ans;
    }
};