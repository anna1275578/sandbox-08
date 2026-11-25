#include <iostream>

struct Node {
    int value;
    Node* next;
};

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int length = 0;
    for (int v = 1; v <= 3; ++v) {
        Node* node = new Node{v, nullptr};
        if (head == nullptr) {
            head = node;  // перший вузол — і голова, і хвіст
        } else {
            tail->next = node;
        }
        tail = node;
        length = length + 1;
    }
    for (Node* n = head; n != nullptr; n = n->next) {
        std::cout << n->value << ' ';
    }
    std::cout << '\n' << length << '\n';
    while (head != nullptr) {
        Node* next = head->next;
        delete head;
        head = next;
    }
}