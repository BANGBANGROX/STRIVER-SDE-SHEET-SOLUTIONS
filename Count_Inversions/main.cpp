//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    typedef long long int ll;

    static ll merge(ll temp[], ll nums[], ll left, ll mid, ll right) {
        ll ans = 0;
        ll i = left;
        ll j = mid + 1;
        ll k = left;

        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp[k] = nums[i];
                ++i;
            }
            else {
                temp[k] = nums[j];
                ans += (mid - i + 1);
                ++j;
            }
            ++k;
        }

        while (i <= mid) {
            temp[k] = nums[i];
            ++k;
            ++i;
        }

        while (j <= right) {
            temp[k] = nums[j];
            ++k;
            ++j;
        }

        for (i = left; i <= right; ++i) {
            nums[i] = temp[i];
        }

        return ans;
    }

    ll mergeSort(ll temp[], ll nums[], ll left, ll right) {
        if (left >= right) return 0;

        ll ans = 0;
        ll mid = (left + ((right - left) >> 1));

        ans += mergeSort(temp, nums, left, mid);
        ans += mergeSort(temp, nums, mid + 1, right);
        ans += merge(temp, nums, left, mid, right);

        return ans;
    }

public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    ll inversionCount(ll nums[], ll n) {
        // Your Code Here
        ll *temp = new ll[n];

        return mergeSort(temp, nums, 0, n - 1);
    }

};

//{ Driver Code Starts.

int main() {

    long long T;
    cin >> T;

    while(T--){
        long long N;
        cin >> N;

        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }

    return 0;
}

// } Driver Code Ends