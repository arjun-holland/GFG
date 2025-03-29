//{ Driver Code Starts
// Driver code
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

/*
class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        vector<pair<int,int>> jobs;
        int n = deadline.size();
        for(int i=0; i<n; i++){
            jobs.push_back({profit[i],deadline[i]});
        }
        sort(jobs.begin(),jobs.end(),[](pair<int,int>& j1,pair<int,int>& j2){
            return j1.first > j2.first;
        });
        int maxDeadline = *max_element(deadline.begin(),deadline.end());
        vector<int> gaunttChart(maxDeadline,0);
        
        for(int i=0; i<jobs.size(); i++){
            int cp = jobs[i].first;
            int cd = jobs[i].second;
            for(int j=cd; j>0; j--){
                if(gaunttChart[j-1] == 0){
                    gaunttChart[j-1] = cp;
                    break;
                }else if(gaunttChart[j-1] < cp){
                    gaunttChart[j-1] = cp;
                    break;
                }
            }
        }
        int nj = 0, p = 0;
        for(int i=0;i<gaunttChart.size();i++){
            if(gaunttChart[i] != 0){
                nj++;
                p += gaunttChart[i];
            }
        }
        return {nj,p};
    }
};
*/
class Solution {
public:
    vector<int> jobSequencing(vector<int>& deadline, vector<int>& profit) {
        int n = deadline.size();
        vector<pair<int, int>> jobs;

        // Step 1: Store jobs as {deadline, profit}
        for (int i = 0; i < n; i++) {
            jobs.push_back({deadline[i], profit[i]});
        }

        // Step 2: Sort jobs by ascending order of deadline
        sort(jobs.begin(), jobs.end());

        // Step 3: Min-Heap to track profits (stores least profit at top)
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // Step 4: Process jobs in ascending order of deadline
        for (int i = 0; i < n; i++) {
            int currDeadline = jobs[i].first;
            int currProfit = jobs[i].second;

            // If jobs can be scheduled without exceeding deadline
            if (minHeap.size() < currDeadline) {
                minHeap.push(currProfit);
            } 
            // Replace least profitable job if current job is more profitable
            else if (!minHeap.empty() && minHeap.top() < currProfit) {
                minHeap.pop();
                minHeap.push(currProfit);
            }
        }

        // Step 5: Calculate total profit
        int totalJobs = minHeap.size();
        int maxProfit = 0;
        while (!minHeap.empty()) {
            maxProfit += minHeap.top();
            minHeap.pop();
        }

        return {totalJobs, maxProfit};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> deadlines, profits;
        string temp;
        getline(cin, temp);
        int x;
        istringstream ss1(temp);
        while (ss1 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            profits.push_back(x);

        Solution obj;
        vector<int> ans = obj.jobSequencing(deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends