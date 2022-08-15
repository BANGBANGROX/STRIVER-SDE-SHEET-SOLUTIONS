//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int>& start, vector<int>& end, int n) {
        // Your code here
        vector<vector<int>> intervals(n);

        for (int i = 0; i < n; ++i) {
            intervals[i] = {start[i], end[i]};
        }

        sort(intervals.begin(), intervals.end());

        int ans = 1;
        int maxR = intervals[0][1];

        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] > maxR) {
                ++ans;
                maxR = intervals[i][1];
            }
            else maxR = min(maxR, intervals[i][1]);
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends