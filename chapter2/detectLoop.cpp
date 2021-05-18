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
    if (!head) {
        std::cout << "\nList Empty, no loop\n";
        return NULL;
    }

    // Use flag variable so that loop doesn't exit on first iteration when both are at the start.
    bool flag = false;
    Node *fast = head;
    Node *slow = head;
    // Let fast runner move at twice the speed of slow runner. When they collide, they will be exactly k nodes
    // from the head of the loop, where k is the distance from the head of the list to the head of the loop.
    while (fast != slow || flag == false) {
        fast = fast->getNext();
        fast = fast->getNext();
        slow = slow->getNext();
        flag = true;
    }

    // With one runner reset to the head, move each runner at the same pace until they meet. They will meet k
    // nodes from the head of the list, or exactly at the head of the loop. Return where they meet.
    fast = head;
    while (fast != slow) {
        slow = slow->getNext();
        fast = fast->getNext();
    }

    return fast;
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

Node* createLoop(LinkedList list, int pos) {
    Node *curr = list.getHead();
    Node *tail = list.getTail();
    int len = list.getLen();

    int count{};
    while (count < pos) {
        curr = curr->getNext();
        count++;
    }
    tail->setNext(curr);

    return curr;
}

int main() {
    LinkedList linkedList{};
    int val{};

    while (std::cin>>val) {
        linkedList.addVal(val);
    }

    linkedList.display();

    std::cout << '\n' << "Head of loop is: "
              << createLoop(linkedList, 2) << '\n';

    std::cout << '\n'
              << "Loop detected at: " << linkedList.detectLoop() << '\n';
}