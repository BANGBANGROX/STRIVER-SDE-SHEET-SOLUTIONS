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
    ListNode* middleNode(ListNode* head) {
         ListNode *slow = head;
         ListNode *fast = head;

         while (fast != NULL && fast->next != NULL) {
             slow = slow->next;
             fast = fast->next->next;
         }

         return slow;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
