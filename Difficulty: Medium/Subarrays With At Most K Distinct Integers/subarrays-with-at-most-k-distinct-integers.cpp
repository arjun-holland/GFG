class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        int ans = 0;
        int i=0,j=0,m=arr.size();
        unordered_map<int,int> mp;
        while(i < m){
            mp[arr[i]]++;
            while(mp.size() > k){
                mp[arr[j]]--;
                if(mp[arr[j]] == 0)mp.erase(arr[j]);
                j++;
            }
            if(mp.size() <= k)ans += (i-j+1);                    
            i++;
        }
        return ans;
    }
};