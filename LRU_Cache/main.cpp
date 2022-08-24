#include<bits/stdc++.h>
using namespace std;

class LRUCache {
    struct ListNode {
        int key;
        int value;
        ListNode *prev;
        ListNode *next;

        ListNode() {
            key = value = -1;
            prev = next = nullptr;
        }
    };

    ListNode *head;
    ListNode *tail;
    unordered_map<int, ListNode *> cache;
    int capacity;

    void addNode(ListNode *node) {
        ListNode *headNext = head->next;
        node->prev = head;
        head->next = node;
        node->next = headNext;
        headNext->prev = node;
    }

    void removeNode(ListNode *node) {
        ListNode *prev = node->prev;
        ListNode *next = node->next;

        prev->next = next;
        next->prev = prev;
    }

public:
    LRUCache(int capacity) {
        head = new ListNode();
        tail = new ListNode();
        this->capacity = capacity;

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            ListNode *node = cache[key];
            int ans = node->value;
            removeNode(node);
            addNode(node);
            return ans;
        }
        else return -1;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            ListNode *node = cache[key];
            removeNode(node);
            node->value = value;
            addNode(node);
        }
        else {
            if (capacity == (int) cache.size()) {
                cache.erase(tail->prev->key);
                removeNode(tail->prev);
            }
            ListNode *newNode = new ListNode();
            newNode->key = key;
            newNode->value = value;
            addNode(newNode);
            cache[key] = newNode;
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
