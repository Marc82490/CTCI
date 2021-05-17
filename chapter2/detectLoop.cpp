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
        Node *getHead() { return head; }
        int getLen();
        Node *detectLoop();
        Node *getTail();

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

int LinkedList::getLen() {
    if (!head) {
        return 0;
    }

    int count{};
    Node *curr = head;
    while (curr != nullptr) {
        curr = curr->getNext();
        count++;
    }

    return count;
}

Node* LinkedList::detectLoop() {
    ;
}

Node* LinkedList::getTail() {
    if (!head) {
        std::cout << "\nList Empty, No Tail\n";
        return nullptr;
    }

    Node *curr = head;
    while (curr->getNext() != nullptr) {
        curr = curr->getNext();
    }

    return curr;
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

void createLoop(LinkedList list, int pos) {
    Node *curr = list.getHead();
    Node *tail = list.getTail();
    int len = list.getLen();

    int count{};
    while (count < pos) {
        curr = curr->getNext();
        count++;
    }
    tail->setNext(curr);
}

int main() {
    LinkedList linkedList{};
    int val{};

    while (std::cin>>val) {
        linkedList.addVal(val);
    }

    linkedList.display();

    createLoop(linkedList, 2);

    // linkedList.display();
}