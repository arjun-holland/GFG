class Solution {
  public:
    string check(string &a,int l,int r){
        while(l >= 0 && r <= a.length() && a[l] == a[r]){
            l--;
            r++;
        }
        return a.substr(l+1,r-l-1);
    }
    string longestPalindrome(string &s) {
        if(s.length() <= 1)return s;
        string res = s.substr(0,1);
        int maxLen = 1;
        for(int i=0; i<s.length(); i++){
            string ol = check(s,i,i);
            string el = check(s,i,i+1);
            if(ol.length() > maxLen){
                maxLen = ol.length();
                res = ol;
            }
            if(el.length() > maxLen){
                maxLen = el.length();
                res = el;
            }
        }
        return res;
    }
};