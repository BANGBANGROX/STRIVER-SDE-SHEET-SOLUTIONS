#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int val) {
        this->val = val;
        next = NULL;
    }
};

class Solution {
public:
    void deleteNode(ListNode* node) {
         node->val = node->next->val;
         node->next = node->next->next;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
