#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0;
        int ans = 0;
        unordered_map<char, int> count;

        for (int r = 0; r < n; ++r) {
            ++count[s[r]];
            while (count[s[r]] > 1) {
                --count[s[l]];
                ++l;
            }
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;

        Solution solution;
        cout << solution.lengthOfLongestSubstring(s) << endl;
    }

    return 0;
}
