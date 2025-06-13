// User function Template for C++

class Solution {
  public:

    bool isValid(int m,vector<int> &st, int k){
        int ct = 1;
        int id = st[0];//initial distance
        for(int i=1;i<st.size();i++){
            if((st[i] - id) >= m){
                ct++;
                id = st[i];
                if(ct >= k)return true;
            }
        }
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(),stalls.end());
        int i = 0,j = stalls[stalls.size()-1];
        int ans = INT_MAX;
        while(i <= j){
            int m = i+(j-i)/2;
            if(isValid(m,stalls,k)){
                ans = m;
                i = m+1;
            }else{
                j = m-1;
            }
        }
        return ans;
        
    }
};