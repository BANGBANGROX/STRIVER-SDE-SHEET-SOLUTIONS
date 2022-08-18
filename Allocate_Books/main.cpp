#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool check(vector<int> &books, int pages, int children) {
       int currentPages = 0;
       int partitions = 1;

       for (int book: books) {
           if (currentPages + book > pages) {
               ++partitions;
               currentPages = 0;
           }
           currentPages += book;
           if (partitions > children || currentPages > pages) return false;
       }

       return true;
    }

public:
    int books(vector<int> &books, int children) {
        int n = books.size();

        if (children < n) return -1;

        int l = 1;
        int r = accumulate(books.begin(), books.end(), 0);

        while (l <= r) {
            int mid = (l + ((r - l) >> 1));
            if (check(books, mid, children)) r = mid - 1;
            else l = mid + 1;
        }

        return l;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<int> books(n);
        for (int &x: books) cin >> x;
        int children;
        cin >> children;

        Solution solution;
        cout << solution.books(books, children) << endl;
    }

    return 0;
}
