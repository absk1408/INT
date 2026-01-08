#include <iostream>
using namespace std;

/* Linked List Node */
struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Function to convert a linked list to an integer
int linkedListToInteger(Node* head) {
    int num = 0;
    while (head != nullptr) {
        num = num * 10 + head->data;
        head = head->next;
    }
    return num;
}

// Helper function to create a linked list from an array
Node* createLinkedList(int arr[], int size) {
    if (size == 0) return nullptr;
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for (int i = 1; i < size; i++) {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return head;
}

// Helper function to print the linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    int arr[] = {1, 2,0, 3, 4,0}; // Represents the number 1234
    int size = sizeof(arr) / sizeof(arr[0]);
    
    Node* head = createLinkedList(arr, size);
    cout << "Linked List: ";
    printList(head);

    int result = linkedListToInteger(head);
    cout << "Converted Integer: " << result << endl;

    return 0;
}
