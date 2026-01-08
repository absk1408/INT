#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    
    Node(int val) {
        data = val;
        next = prev = nullptr;
    }
};

// Function to reverse a doubly linked list
Node* reverseDLL(Node* head) {
    Node* curr=head; Node* back=nullptr;
    while(curr!=nullptr){
        Node* temp=curr->next;
        curr->next=back;
        curr->prev=temp;
        back=curr;
        curr=temp;
    }
    return back;
}

// Function to print DLL
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Driver code
int main() {
    // Creating a sample DLL: 10 <-> 20 <-> 30 <-> 40
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->prev = head;
    head->next->next = new Node(30);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(40);
    head->next->next->next->prev = head->next->next;

    cout << "Original DLL: ";
    printList(head);

    head = reverseDLL(head);

    cout << "Reversed DLL: ";
    printList(head);

    return 0;
}
