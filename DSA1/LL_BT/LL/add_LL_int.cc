#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
void printList(ListNode* head);
// Reverse a linked list
ListNode* reverse(ListNode* head) {
    ListNode* prev = NULL;
    while (head) {
        ListNode* nextNode = head->next;
        head->next = prev;
        prev = head;
        head = nextNode;
    }
    return prev;
}

// Add two reversed lists
ListNode* addTwoLists(ListNode* l1, ListNode* l2) {
    printList(l1);
    cout<<endl;
    printList(l2);
    cout<<endl;
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) { sum += l1->val; l1 = l1->next; }
        if (l2) { sum += l2->val; l2 = l2->next; }

        carry = sum / 10;
        curr->next = new ListNode(sum % 10);
        curr = curr->next;
    }

    return dummy->next;
}

// Utility: create list from vector
ListNode* createList(const vector<int>& nums) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int n : nums) {
        if (!head) {
            head = new ListNode(n);
            tail = head;
        } else {
            tail->next = new ListNode(n);
            tail = tail->next;
        }
    }
    return head;
}

// Print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Main logic for forward-ordered sum
ListNode* addTwoForward(ListNode* l1, ListNode* l2) {
    l1 = reverse(l1);
    l2 = reverse(l2);
    

    ListNode* sum = addTwoLists(l1, l2);
    return reverse(sum);
}

// Driver code
int main() {
    ListNode* l1 = createList({0,0,0 ,9});
    ListNode* l2 = createList({5});

    ListNode* result = addTwoForward(l1, l2);

    cout << "Result: ";
    printList(result); // Output: 7 -> 0 -> 3 -> 3

    return 0;
}
