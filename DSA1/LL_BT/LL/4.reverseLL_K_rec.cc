#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* curr = head;
    int count = 0;
    
    // Count the number of nodes in the list
    while (curr && count < k) {
        curr = curr->next;
        count++;
    }
    
    // If we have k nodes, reverse them
    if (count == k) {
        curr = head;
        ListNode* prev = nullptr, *next = nullptr;
        for (int i = 0; i < k; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        // Recursively call for the next k nodes
        head->next = reverseKGroup(curr, k);
        return prev;
    }
    
    return head; // Return head if remaining nodes are less than k
}

// Utility function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Utility function to create a linked list from an array
ListNode* createList(int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;
    for (int i = 1; i < size; i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int k = 3;
    ListNode* head = createList(arr, 8);

    cout << "Original List: ";
    printList(head);

    head = reverseKGroup(head, k);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}
