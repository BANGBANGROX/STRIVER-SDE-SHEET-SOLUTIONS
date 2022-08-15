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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *resultHead = new ListNode(-1);
        ListNode *resultTail = resultHead;

        while (list1 != NULL && list2 != NULL) {
            if (list1->val < list2->val) {
                resultTail->next = list1;
                list1 = list1->next;
            }
            else {
                resultTail->next = list2;
                list2 = list2->next;
            }
            resultTail = resultTail->next;
        }

        resultTail->next = (list1 == NULL) ? list2 : list1;

        return resultHead->next;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
