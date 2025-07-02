class Solution {
  public:
    int totalElements(vector<int> &arr) {
        int ans = 0;
        int i=0,j=0,k=arr.size();
        unordered_map<int,int> st;
        
        while(i < k){
            st[arr[i]]++;
            while(j < i && st.size() > 2){
                st[arr[j]]--;
                if(st[arr[j]] == 0)st.erase(arr[j]);
                j++;
            }
            ans = max(ans,(i-j+1));
            i++;
        }
        return ans;
    }
};