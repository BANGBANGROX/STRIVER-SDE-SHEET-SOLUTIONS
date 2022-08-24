#include<bits/stdc++.h>
using namespace std;

class MedianFinder {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<>> minHeap;

public:
    MedianFinder() {

    }

    void addNum(int num) {
       if (maxHeap.empty() || maxHeap.top() >= num) {
           maxHeap.push(num);
       }
       else {
           minHeap.push(num);
       }

       if (maxHeap.size() > minHeap.size() + 1) {
           minHeap.push(maxHeap.top());
           maxHeap.pop();
       }
       else if (minHeap.size() > maxHeap.size()) {
           maxHeap.push(minHeap.top());
           minHeap.pop();
       }
    }

    double findMedian() {
       if (maxHeap.size() == minHeap.size()) {
           return (maxHeap.top() + minHeap.top()) / 2.0;
       }

       return maxHeap.top();
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
