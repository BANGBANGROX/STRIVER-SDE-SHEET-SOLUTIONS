#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int hare = nums[nums[0]];
        int tortoise = nums[0];

        while (hare != tortoise) {
            hare = nums[nums[hare]];
            tortoise = nums[tortoise];
        }

        tortoise = 0;

        while (hare != tortoise) {
            hare = nums[hare];
            tortoise = nums[tortoise];
        }

        return hare;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {

    }
}
