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
    int findLength(ListNode *head) {
        int len = 0;

        while (head != NULL) {
            ++len;
            head = head->next;
        }

        return len;
    }

public:
    ListNode* rotateRight(ListNode* head, int k) {
        int len = findLength(head);

        if (len == 0) return NULL;

        k %= len;

        if (k == 0) return head;

        int idx = 0;
        ListNode *current = head;

        while (idx < len - k - 1) {
            current = current->next;
            ++idx;
        }

        ListNode *next = current->next;
        ListNode *tail = current;

        while (tail->next != NULL) {
            tail = tail->next;
        }

        tail->next = head;
        current->next = NULL;

        return next;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
