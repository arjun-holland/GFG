class Solution {
  public:
    vector<vector<string>> palinParts(string &s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(s,0,temp,ans);
        return ans;
    }
  private:
    void solve(string& s,int id,vector<string>& temp,vector<vector<string>>& ans){
        if(id >= s.length()){
            ans.push_back(temp);
            return;
        }
        for(int i = id; i < s.length(); i++){
            string cur = s.substr(id,i-id+1);
            if(isPal(cur)){
                temp.push_back(cur);
                solve(s,i+1,temp,ans);
                temp.pop_back();
            }
        }
    }
    
    bool isPal(string& s){
        int i=0,j=s.length()-1;
        while(i<j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};