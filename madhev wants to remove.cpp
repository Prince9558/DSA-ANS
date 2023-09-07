#include <iostream>

using namespace std;

// Define a structure for a singly linked list node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to insert a new node at the end of the linked list
Node* insertAtEnd(Node* head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        return newNode;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to remove nodes with values greater than 'x'
Node* removeNodesGreaterThanX(Node* head, int x) {
    while (head && head->data > x) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    if (!head) {
        return nullptr;
    }
    Node* current = head;
    while (current->next) {
        if (current->next->data > x) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        } else {
            current = current->next;
        }
    }
    return head;
}

// Function to display the linked list
void displayLinkedList(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    int n, x;
    cin >> n;
    Node* head = nullptr;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        head = insertAtEnd(head, val);
    }

    cin >> x;

    cout << "Original Linked List: ";
    displayLinkedList(head);

    head = removeNodesGreaterThanX(head, x);

    cout << "Modified Linked List: ";
    displayLinkedList(head);

    // Free memory by deleting all nodes in the modified linked list
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

