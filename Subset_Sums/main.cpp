//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    vector<int> ans;

    void generate(int index, vector<int> &nums, int currentSum) {
        if (index == (int) nums.size()) {
            ans.push_back(currentSum);
            return;
        }

        // Leave the current number
        generate(index + 1, nums, currentSum);

        // Take the current number
        generate(index + 1, nums, currentSum + nums[index]);
    }

public:
    vector<int> subsetSums(vector<int> &nums, int n) {
        // Write Your Code here
        sort(nums.begin(), nums.end());

        generate(0, nums, 0);

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends