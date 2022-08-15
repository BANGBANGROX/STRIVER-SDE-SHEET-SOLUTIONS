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
    ListNode *reverseList(ListNode *head) {
        ListNode *current = head;
        ListNode *prev = NULL;

        while (current != NULL) {
            ListNode *next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) return head;

        int cnt = 1;
        ListNode *current = head;

        while (current != NULL && cnt < k) {
            current = current->next;
            ++cnt;
        }

        if (cnt < k || current == NULL) return head;

        ListNode *next = current->next;
        current->next = NULL;
        ListNode *result = reverseList(head);

        head->next = reverseKGroup(next, k);

        return result;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
