class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        // Code here
        int d = 0;
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            if(mp.find(arr[i]) == mp.end()){
                mp[arr[i]] = i;
            }else{
                int prev_d = mp[arr[i]];
                int cur_d = i;
                d = max(d, (cur_d-prev_d));
            }
        }
        return d;
    }
};