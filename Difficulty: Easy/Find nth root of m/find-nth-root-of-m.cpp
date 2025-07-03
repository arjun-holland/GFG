class Solution {
  public:
    int nthRoot(int n, int m) {
        int l = 1, r = 1e9;
        int ans = -1;
        while(l <= r){
            int md = (l+r)/2;
            if(pow(md,n) == m){
                return md;
            }
            else if(pow(md,n) < m){
                l = md + 1;
            }else{
                r = md - 1;
            }
        }
        return ans;
    }
};