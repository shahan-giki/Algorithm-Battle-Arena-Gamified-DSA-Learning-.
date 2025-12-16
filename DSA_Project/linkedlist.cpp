#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Reverse - Iterative O(n) time, O(1) space
Node* reverseIterative(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    return prev;
}

// Reverse - Recursive O(n) time, O(n) space
Node* reverseRecursive(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return head;
    
    Node* newHead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    
    return newHead;
}

// Cycle Detection - Floyd's Algorithm O(n) time, O(1) space
bool detectCycle(Node* head) {
    if (head == nullptr) return false;
    
    Node* slow = head;
    Node* fast = head;
    
    
    }
    
    return false;
}

// Find Middle - Two Pointer O(n) time, O(1) space
Node* findMiddle(Node* head) {
    if (head == nullptr) return nullptr;
    
    Node* slow = head;
    Node* fast = head;
    
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;

}

