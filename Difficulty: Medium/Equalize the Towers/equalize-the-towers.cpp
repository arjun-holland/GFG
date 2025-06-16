class Solution {
  public:
    bool isValid(int m,vector<int>& heights, vector<int>& cost){
        long long c1 = 0;
        long long c2 = 0;
        for(int i=0;i<heights.size();i++){
            c1 += (long long)(abs(heights[i]-m)*cost[i]);
            c2 += (long long)(abs(heights[i]-(m+1))*cost[i]);
        }
        return c1 < c2;
    }
    int minCost(vector<int>& heights, vector<int>& cost) {  
        int l = *min_element(heights.begin(),heights.end());
        int r = *max_element(heights.begin(),heights.end());
        int reqHeight = INT_MAX;
        while(l <= r){
            int m = l+(r-l)/2;
            if(isValid(m,heights,cost)){
                reqHeight = m;
                r = m - 1;
            }else{
                l = m + 1;
            }
        }
        int res = 0;
        for(int i=0;i<heights.size();i++){
            res += abs(heights[i]-reqHeight)*cost[i];
        }
        return res;
    }
};
