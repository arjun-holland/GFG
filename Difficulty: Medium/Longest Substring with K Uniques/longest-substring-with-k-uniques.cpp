class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        unordered_map<char,int> mp;
        int l = 0,j = 0,r = s.length()-1;
        int ans =  0;
        while(l <= r){
            mp[s[l]]++;
            while(mp.size() > k){
                mp[s[j]]--;
                if(mp[s[j]] == 0)mp.erase(s[j]);
                j++;
            }
            if(mp.size() == k)ans = max(ans,(l-j+1));
            l++;
        }
        return (ans == 0)? -1 : ans;
    }
};