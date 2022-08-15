//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(const int start[], const int end[], int n) {
        // Your code here
        vector<vector<int>> intervals;
        int ans = 1;

        for (int i = 0; i < n; ++i) {
            intervals.push_back({start[i], end[i]});
        }

        sort(intervals.begin(), intervals.end());

        int maxR = intervals[0][1];

        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] > maxR) {
                maxR = intervals[i][1];
                ++ans;
            }
            else maxR = min(intervals[i][1], maxR);
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends