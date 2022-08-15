#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *next;
    Node *random;

    Node(int val) {
        this->val = val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node *, Node *> mp;
        Node *current = head;
        Node *previous = NULL;

        while (current != NULL) {
            Node *clone = new Node(current->val);
            if (previous == NULL) {
                mp[current] = clone;
                previous = current;
                current = current->next;
                continue;
            }
            Node *pClone = mp[previous];
            pClone->next = clone;
            previous = current;
            mp[current] = clone;
            current = current->next;
        }

        current = head;

        while (current != NULL) {
            if (current->random == NULL) {
                current = current->next;
                continue;
            }
            Node *random = current->random;
            Node *clone = mp[current];
            Node *rClone = mp[random];
            clone->random = rClone;
            current = current->next;
        }

        return mp[head];
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
