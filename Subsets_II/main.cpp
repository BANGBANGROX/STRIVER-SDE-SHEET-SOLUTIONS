#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> ans;
    set<vector<int>> visited;

    void generate(int index, vector<int> &nums, vector<int> &currentSubset) {
        if (index == (int) nums.size()) {
            if (visited.find(currentSubset) == visited.end()) {
                ans.push_back(currentSubset);
                visited.insert(currentSubset);
            }
            return;
        }

        // Take the number
        currentSubset.push_back(nums[index]);
        generate(index + 1, nums, currentSubset);
        currentSubset.pop_back();

        // Leave the number
        generate(index + 1, nums, currentSubset);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());

        vector<int> currentSubset;

        generate(0, nums, currentSubset);

        return ans;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int &x: nums) cin >> x;

        Solution solution;
        vector<vector<int>> ans = solution.subsetsWithDup(nums);
        for (vector<int> &x: ans) {
            for (int &y: x) cout << y << " ";
            cout << endl;
        }
    }

    return 0;
}
