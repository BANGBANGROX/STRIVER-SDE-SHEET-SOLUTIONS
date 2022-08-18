//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    int upperBound(const int nums[], int n, int key) {
        int l = 0;
        int r = n - 1;

        while (l <= r) {
            int mid = (l + ((r - l) >> 1));
            if (nums[mid] > key) r = mid - 1;
            else l = mid + 1;
        }

        return l;
    }

public:
    int kthElement(int nums1[], int nums2[], int m, int n, int k) {
          int l = min(nums1[0], nums2[0]);
          int r = max(nums1[m - 1], nums2[n - 1]);

          while (l <= r) {
              int mid = (l + ((r - l) >> 1));
              int cnt1 = upperBound(nums1, m, mid);
              int cnt2 = upperBound(nums2, n, mid);
              if (cnt1 + cnt2 >= k) r = mid - 1;
              else l = mid + 1;
          }

          return l;
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, m, n, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends