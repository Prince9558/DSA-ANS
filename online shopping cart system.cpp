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

// Function to delete a node at a specified position in the linked list
Node* deleteNodeAtPosition(Node* head, int position) {
    if (!head) {
        return nullptr;
    }
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* current = head;
    int count = 1;
    while (current && count < position - 1) {
        current = current->next;
        count++;
    }
    if (!current || !current->next) {
        return head; // Position is out of bounds
    }
    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
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
    int n;
    cin >> n;
    Node* head = nullptr;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        head = insertAtEnd(head, val);
    }

    int position;
    cin >> position;

    head = deleteNodeAtPosition(head, position);

    displayLinkedList(head);

    // Free memory by deleting all nodes in the modified linked list
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

