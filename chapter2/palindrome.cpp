#include <iostream>

class Node {
    public:
        Node(int val) : data{val} {}
        int getData() { return data; }
        Node *getNext() { return next; }
        void setNext(Node *node) { next = node; }

    private:
        int data{};
        Node *next{};
};

class LinkedList {
    public:
        void addVal(int val);
        void display();
        bool isPalindrome();
        void addValToEnd(int val);
        Node *getHead() { return head; }

    private:
        Node *head{};
};

void LinkedList::addVal(int val) {
    Node *newNode = new Node(val);

    if (!head) {
        head = newNode;
        return;
    }

    newNode->setNext(head);
    head = newNode;
}

void LinkedList::addValToEnd(int val) {
    Node *newNode = new Node(val);

    if (!head) {
        head = newNode;
        return;
    }

    Node *curr = head;
    while (curr->getNext() != nullptr) {
        curr = curr->getNext();
    }
    curr->setNext(newNode);
}

bool LinkedList::isPalindrome() {
    LinkedList reverse{};

    Node *curr = head;
    while (curr != nullptr) {
        reverse.addVal(curr->getData());
        curr = curr->getNext();
    }

    curr = head;
    Node *headReverse = reverse.getHead();
    while (curr != nullptr && headReverse != nullptr) {
        if (curr->getData() == headReverse->getData()) {
            curr = curr->getNext();
            headReverse = headReverse->getNext();
        } else {
            return false;
        }
    }
    return true;
}

void LinkedList::display() {
    if (!head) {
        std::cout << "\nList Empty\n";
        return;
    }

    std::cout << '\n';
    Node *curr = head;
    while (curr->getNext() != nullptr) {
        std::cout << curr->getData() << "->";
        curr = curr->getNext();
    }
    std::cout << curr->getData() << '\n';
}

int main() {
    LinkedList linkedList{};
    int val{};

    while (std::cin>>val) {
        linkedList.addVal(val);
    }

    linkedList.display();

    std::cout << linkedList.isPalindrome();
}