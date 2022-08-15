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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head;
        int cnt = 1;

        while (cnt < n) {
            fast = fast->next;
            ++cnt;
        }

        ListNode *slow = head;
        ListNode *prev = NULL;

        while (fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }

        if (prev == NULL) return head->next;

        prev->next = slow->next;
        delete slow;

        return head;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
