#include <iostream>

// Define a structure for the node in the linked list
struct Node {
    int data;
    Node* next;
};

// Function to create a new node with the given data
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtFront(Node* header, int data) {
    Node* newNode = createNode(data);
    newNode->next = header->next;
    header->next = newNode;
}

// Function to print the elements of the list
void printList(Node* header) {
    Node* temp = header->next; // Skip the header node

    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }

    std::cout << std::endl;
}

int main() {
    Node* header = createNode(0); // Create the header node
    int value;

    while (true) {
        std::cin >> value;
        if (value == -1) {
            break;
        }
        insertAtFront(header, value);
    }

    // Print the updated list
    printList(header);

    return 0;
}

