#include <iostream>
#include <string>

using namespace std;

// Define a structure for a singly linked list node
struct Node {
    string data;
    Node* next;
    Node(const string& val) : data(val), next(nullptr) {}
};

// Function to insert a new node at the end of the linked list
Node* insertAtEnd(Node* head, const string& val) {
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

// Function to delete alternate nodes from the linked list
Node* deleteAlternateNodes(Node* head) {
    if (!head) {
        return nullptr;
    }
    Node* current = head;
    while (current && current->next) {
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        current = current->next;
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
    int n;
    cin >> n;
    Node* head = nullptr;

    for (int i = 0; i < n; i++) {
        string val;
        cin >> val;
        head = insertAtEnd(head, val);
    }

    cout << "Linked list data: ";
    displayLinkedList(head);

    head = deleteAlternateNodes(head);

    cout << "After deleting alternate node:";
    displayLinkedList(head);

    // Free memory by deleting all nodes in the modified linked list
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

