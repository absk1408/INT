#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to reverse k nodes in the list
Node* reverseKGroup(Node* head, int k) {
    Node* curr = head;
    int count = 0;

    // Check if there are at least k nodes left
    while (curr && count < k) {
        curr = curr->next;
        count++;
    }

    if (count < k) return head; // Not enough nodes to reverse

    // Reverse k nodes
    Node* prev = nullptr;
    curr = head;
    Node* next = nullptr;
    count = 0;
    
    while (curr && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // Recursively call for the next part of the list
    if (next != nullptr) {
        head->next = reverseKGroup(curr, k);
    }

    return prev; // prev becomes new head of the reversed group
}

// Utility function to print list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Sample usage
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    int k = 3;

    cout << "Original list: ";
    printList(head);

    head = reverseKGroup(head, k);

    cout << "Reversed in groups of " << k << ": ";
    printList(head);

    return 0;
}
