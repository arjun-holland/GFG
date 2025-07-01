class Solution {
  public:
    int substrCount(string &s, int k) {
        // code here
        int ans = 0;
        int i=0,j=0,n=s.length();
        int dc = 0;
        unordered_map<char,int> mp;
        
        while(i < n){
            mp[s[i]]++;
            if(mp.size() == k-1){
                if((i-j+1) == k){
                    ans++;
                    mp[s[j]]--;
                    if(mp[s[j]] == 0)mp.erase(s[j]);
                    j++;
                }
                else{
                    while((i-j+1) > k){
                        mp[s[j]]--;
                        if(mp[s[j]] == 0)mp.erase(s[j]);
                        j++;
                    }
                    if((i-j+1) == k && mp.size() == k-1){
                        ans++;
                        mp[s[j]]--;
                        if(mp[s[j]] == 0)mp.erase(s[j]);
                        j++;
                    }
                }
            }else if(mp.size() > k-1){
                mp[s[j]]--;
                if(mp[s[j]] == 0)mp.erase(s[j]);
                j++;
            }
            i++;
        }
        return ans;
    }
};