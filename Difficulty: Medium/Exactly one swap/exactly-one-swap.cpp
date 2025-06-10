class Solution {
  public:
    int countStrings(string &s) {
        unordered_map<char,int> mp;
        for(char c : s){
            mp[c]++;
        }
        int ms = mp.size();
        int ans = 0;
        int n = s.length();
        for(int i=0;i<n-1;i++){
            char c = s[i];
            if(mp[c] == 1){
                ans += (n-i-1);
                mp[c] = 0;
            }else {
                int hs = mp[c];
                hs--;
                ans += (n-1-i-hs);
                mp[c]--;
            }
        }
        if(ms == s.length())return ans;
        return ans+1;
    }
};
