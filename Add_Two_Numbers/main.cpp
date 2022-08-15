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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *resultHead = new ListNode(-1);
        ListNode *resultTail = resultHead;
        int carry = 0;

        while (l1 != NULL && l2 != NULL) {
            int val = (l1->val + l2->val + carry);
            int data = val % 10;
            carry = val / 10;
            resultTail->next = new ListNode(data);
            l1 = l1->next;
            l2 = l2->next;
            resultTail = resultTail->next;
        }

        while (l1 != NULL) {
            int val = (l1->val + carry);
            int data = val % 10;
            carry = val / 10;
            resultTail->next = new ListNode(data);
            l1 = l1->next;
            resultTail = resultTail->next;
        }

        while (l2 != NULL) {
            int val = (l2->val + carry);
            int data = val % 10;
            carry = val / 10;
            resultTail->next = new ListNode(data);
            l2 = l2->next;
            resultTail = resultTail->next;
        }

        if (carry > 0) resultTail->next = new ListNode(carry);

        return resultHead->next;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
