#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void insertAtBeginning(Node*& head, int data) {
    Node* newNode = new Node{data, nullptr, nullptr};
    if (head == nullptr) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertAtEnd(Node*& head, int data) {
    Node* newNode = new Node{data, nullptr, nullptr};
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteAtBeginning(Node*& head) {
    if (head == nullptr) return;
    Node* temp = head;
    head = head->next;
    if (head) head->prev = nullptr;
    delete temp;
}

void deleteAtEnd(Node*& head) {
    if (head == nullptr) return;
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->prev->next = nullptr;
    delete temp;
}

void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;

    insertAtBeginning(head, 10);
    insertAtBeginning(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);

    cout << "Doubly Linked List: ";
    display(head);

    deleteAtBeginning(head);
    cout << "After deleting at beginning: ";
    display(head);

    deleteAtEnd(head);
    cout << "After deleting at end: ";
    display(head);

    return 0;
}
