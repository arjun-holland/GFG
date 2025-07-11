class Solution {
  public:
    string minSum(vector<int> &arr) {
        // CodeGenius
        string n1,n2;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            if(i%2==0) n1+=to_string(arr[i]);
            else n2+=to_string(arr[i]);
        }
        reverse(n1.begin(),n1.end());
        reverse(n2.begin(),n2.end());
        string ans;
        int i=0,j=0;
        int carry=0;
        while(i<n1.size() || j<n2.size()){
            int sum=0;
            if(i<n1.size())sum+=n1[i++]-'0';
            if(j<n2.size())sum+=n2[j++]-'0';
            sum+=carry;
            carry=sum/10;
            sum%=10;
            ans+=to_string(sum);
        }
        ans+=to_string(carry);
        while(ans.back()=='0')ans.pop_back();
        reverse(ans.begin(),ans.end());
        return ans;
        }
};