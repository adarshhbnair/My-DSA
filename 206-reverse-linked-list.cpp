#include <iostream>
#include <vector> // For std::vector

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *current = head;
        ListNode *previous = nullptr;
        ListNode *next;

        while (current) {
            next = current->next; // Store the next node
            current->next = previous; // Reverse the link
            previous = current; // Move previous to current
            current = next; // Move to the next node
        }

        return previous; // New head of the reversed list
    }
};

// Helper function to print the linked list
void printList(ListNode *head) {
    ListNode *current = head;
    while (current) {
        std::cout << current->val << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

// Helper function to create a linked list from an array
ListNode* createList(const std::vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode *head = new ListNode(values[0]);
    ListNode *current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

int main() {
    Solution solution;

    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = createList({1, 2, 3, 4, 5});
    std::cout << "Original list: ";
    printList(head);

    // Reverse the linked list
    ListNode *reversedHead = solution.reverseList(head);
    std::cout << "Reversed list: ";
    printList(reversedHead);

    // Clean up memory (not shown here for simplicity)
    return 0;
}