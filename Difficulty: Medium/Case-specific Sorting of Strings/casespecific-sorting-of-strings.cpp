class Solution {
  public:
    string caseSort(string& s) {
        // code here
        vector<char> up,lo;
        for(char c: s){
            if(islower(c)){
                lo.push_back(c);
            }else{
                up.push_back(c);
            }
        }
        sort(up.begin(),up.end());
        sort(lo.begin(),lo.end());
        string res = "";
        for(char c : s){
            if(islower(c)){
                res += *lo.begin();
                lo.erase(lo.begin());
            }else{
                res += *up.begin();
                up.erase(up.begin());
            }
        }
        return res;
    }
};