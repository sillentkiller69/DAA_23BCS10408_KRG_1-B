#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAtBeginning(Node*& tail, int data) {
    Node* newNode = new Node{data, nullptr};
    if (tail == nullptr) {
        tail = newNode;
        tail->next = tail; // circular
        return;
    }
    newNode->next = tail->next;
    tail->next = newNode;
}

void insertAtEnd(Node*& tail, int data) {
    Node* newNode = new Node{data, nullptr};
    if (tail == nullptr) {
        tail = newNode;
        tail->next = tail;
        return;
    }
    newNode->next = tail->next;
    tail->next = newNode;
    tail = newNode;
}

void deleteAtBeginning(Node*& tail) {
    if (tail == nullptr) return;
    Node* head = tail->next;
    if (head == tail) { // only one node
        delete head;
        tail = nullptr;
        return;
    }
    tail->next = head->next;
    delete head;
}

// Delete at End
void deleteAtEnd(Node*& tail) {
    if (tail == nullptr) return;
    Node* temp = tail->next;
    if (tail == tail->next) { // single node
        delete tail;
        tail = nullptr;
        return;
    }
    while (temp->next != tail) {
        temp = temp->next;
    }
    temp->next = tail->next;
    delete tail;
    tail = temp;
}

void display(Node* tail) {
    if (tail == nullptr) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = tail->next;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << "(back to head)\n";
}

int main() {
    Node* tail = nullptr;

    insertAtBeginning(tail, 10);
    insertAtBeginning(tail, 20);
    insertAtEnd(tail, 30);
    insertAtEnd(tail, 40);

    cout << "Circular Linked List: ";
    display(tail);

    deleteAtBeginning(tail);
    cout << "After deleting at beginning: ";
    display(tail);

    deleteAtEnd(tail);
    cout << "After deleting at end: ";
    display(tail);

    return 0;
}
