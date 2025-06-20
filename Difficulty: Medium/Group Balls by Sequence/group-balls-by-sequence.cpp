class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
        int n = arr.size();
        if(n % k != 0)return false;
        
        map<int,int> ms;
        for(int e : arr)
            ms[e]++;
            
        while(!ms.empty()){
            int se = ms.begin()->first;
            ms[se]--;
            if(ms[se] == 0)ms.erase(se);
            
            int sz = 1;
            while(sz < k){
                int ne = se+1;
                if(ms.find(ne) == ms.end())return false;
                ms[ne]--;
                if(ms[ne] == 0)ms.erase(ne);
                se = ne;
                sz++;
            }
        }
        
        return true;
    }
};