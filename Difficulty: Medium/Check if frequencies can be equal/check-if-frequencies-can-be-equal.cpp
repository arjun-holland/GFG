class Solution {
public:
    bool sameFreq(string& s) {
        unordered_map<char,int> freq;
        for(char c : s){
            freq[c]++;
        }

        unordered_map<int,int> freqCount;
        for(auto& p : freq){
            freqCount[p.second]++;
        }

         if (freqCount.size() == 1) {
            return true; // All frequencies are the same
        }

        if (freqCount.size() > 2) {
            return false; // More than 2 different frequencies = not fixable
        }

        // Extract frequencies and their counts
        auto it = freqCount.begin();
        int f1 = it->first, c1 = it->second;
        it++;
        int f2 = it->first, c2 = it->second;

        // Ensure f1 is smaller
        if (f1 > f2) {
            swap(f1, f2);
            swap(c1, c2);
        }

        // Case 1: lower freq is 1 and occurs once → remove that character
        if (f1 == 1 && c1 == 1) {
            return true;
        }

        // Case 2: higher freq is just 1 more and occurs once → reduce it
        if ((f2 - f1 == 1) && c2 == 1) {
            return true;
        }

        return false;
    }
};