class Solution {
  public:
    bool isValid(vector<int>&ans,int m,int h){
        int hr = 0;
        for(int e : ans){
            hr += (e < m)?1:ceil(float(e)/float(m));
        }
        return hr <= h;
    }
    int kokoEat(vector<int>& arr, int k) {
        int n = arr.size();
        int l = 1,r = *max_element(arr.begin(),arr.end());
        int ans = INT_MAX;
        while(l<=r){
            int m = l+(r-l)/2;
            if(isValid(arr,m,k)){
                ans = m;
                r = m-1;
            }else{
                l = m+1;
            }
        }
        return ans;
    }
};