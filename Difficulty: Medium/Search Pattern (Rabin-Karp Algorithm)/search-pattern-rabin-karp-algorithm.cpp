// class Solution {
//   public:
//     int mod = 1e7+9;
//     long long calHash(string s, long long& r, int m){
//         long long fac = 1,ans = 0;
//         for(int i = m-1; i>= 0; i--){
//             ans += ((s[i]-'a')*fac)%mod;
//             fac = (fac * r)%mod;
//         }
//         return ans%mod;
//     }
//     vector<int> search(string &pat, string &txt) {
//         // code here.
//         vector<int> res;
//         int m = pat.size(),n = txt.size();
//         if(n < m)return res;
        
//         long long maxWeight = 1,radix = 26;
//         for(int i=0;i<=m;i++){
//             maxWeight = (radix*maxWeight) % mod;  //maxWeight = pow(26,m)%mod
//         }
        
//         long long patHash = calHash(pat, radix, m);
//         long long txtHash;
//         for(int i=0;i<=n-m;i++){
//             if(i == 0){
//                 txtHash = calHash(txt, radix, m);
//             }else{
//                 txtHash = ((txtHash*radix)%mod - ((txt[i-1]-'a')*maxWeight)%mod + (txt[i+m-1]-'a') + mod)%mod;
//             }
            
//             if(txtHash == patHash){
//                 for(int j=0;j<m;j++){
//                     if(pat[j] != txt[j+i])break;
//                     if(j == m-1)res.push_back(i+1);
//                 }
//             }
//         }
//         return res;
//     }
// };


class Solution {
public:
    int mod = 1e7 + 9;

    long long calHash(const string &s, int start, int m, long long radix) {
        long long hash = 0;
        for (int i = 0; i < m; ++i) {
            hash = (hash * radix + (s[start + i] - 'a')) % mod;
        }
        return hash;
    }

    vector<int> search(string &pat, string &txt) {
        vector<int> res;
        int m = pat.size(), n = txt.size();
        if (n < m) return res;

        long long radix = 26;
        long long patHash = calHash(pat, 0, m, radix);
        long long txtHash = calHash(txt, 0, m, radix);

        // Precompute radix^(m-1) % mod
        long long RM = 1;
        for (int i = 1; i < m; ++i) {
            RM = (RM * radix) % mod;
        }

        for (int i = 0; i <= n - m; ++i) {
            if (txtHash == patHash) {
                bool match = true;
                for (int j = 0; j < m; ++j) {
                    if (txt[i + j] != pat[j]) {
                        match = false;
                        break;
                    }
                }
                if (match) res.push_back(i + 1); // 1-based indexing
            }

            // Rolling hash
            if (i < n - m) {
                txtHash = (txtHash - ((txt[i] - 'a') * RM) % mod + mod) % mod;
                txtHash = (txtHash * radix + (txt[i + m] - 'a')) % mod;
            }
        }

        return res;
    }
};
