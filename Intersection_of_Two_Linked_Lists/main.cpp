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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *currentA = headA;
        ListNode *currentB = headB;

        while (currentA != NULL && currentB != NULL) {
            currentA = currentA->next;
            currentB = currentB->next;
        }

        if (currentA == NULL) {
            ListNode *tempB = headB;

            while (currentB != NULL) {
                currentB = currentB->next;
                tempB = tempB->next;
            }

            currentB = tempB;
            currentA = headA;
        }
        else if (currentA != NULL) {
            ListNode *tempA = headA;

            while (currentA != NULL) {
                currentA = currentA->next;
                tempA = tempA->next;
            }

            currentA = tempA;
            currentB = headB;
        }

        while (currentA != currentB) {
            currentA = currentA->next;
            currentB = currentB->next;
        }

        return currentA;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
