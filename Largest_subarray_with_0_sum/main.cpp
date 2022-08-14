//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution {
public:
    int maxLen(vector<int> &nums, int n) {
        // Your code here
        int l = 0;
        int maxLen = 0;
        int currentSum = 0;
        unordered_map<int, int> indexSum;

        for (int i = 0; i < n; ++i) {
            currentSum += nums[i];
            if (currentSum == 0) maxLen = i + 1;
            if (indexSum.find(currentSum) != indexSum.end()) {
                maxLen = max(maxLen, i - indexSum[currentSum]);
            }
            else indexSum[currentSum] = i;
        }

        return maxLen;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends