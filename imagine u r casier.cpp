#include <iostream>

using namespace std;

// Define the structure for a singly-linked list node
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

// Function to insert a node at the beginning of a linked list
void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

// Function to calculate the sum of the last m nodes in the linked list
int sumLastMNodes(Node* head, int m) {
    int sum = 0;
    Node* current = head;
    
    // Traverse the first m nodes and calculate the sum
    for (int i = 0; i < m && current != nullptr; i++) {
        sum += current->data;
        current = current->next;
    }

    return sum;
}

int main() {
    int n;
    cin >> n;
    
    Node* head = nullptr;

    // Insert elements into the linked list
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        insertAtBeginning(head, value);
    }

    int m;
    cin >> m;

    int result = sumLastMNodes(head, m);
    cout << result << endl;

    // Clean up memory by deleting the linked list
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

