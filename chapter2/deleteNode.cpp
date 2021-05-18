#include <iostream>

// using namespace std;

class Node {
    public:
        Node(int val) : data{val} {}
        int getData() { return data; }
        void setNext(Node *node) { next = node; }
        Node *getNext() { return next; }
        void setData(int val) { data = val; }

    private:
        int data{};
        Node *next{};
};

class LinkedList {
    public:
        void addVal(int val);
        void deleteNode(Node *node);
        void display();
        Node *nodeAddr(int pos);

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

void LinkedList::deleteNode(Node* node) {
    if (!node) {
        std::cout << "\nNode Invalid\n";
        return;
    }

    if (!head) {
        std::cout << "\nList Empty\n";
        return;
    }

    // As long as the node is not at the end of the list, copy the value of the next node into the current node 
    // (the node to delete), copy the next pointer from the next node into the current node, and slice out the next node.
    if (node->getNext() != nullptr) {
        Node *next = node->getNext();
        node->setData(next->getData());
        node->setNext(next->getNext());
    } else {
        std::cout << "\nNode at end of list, cannot remove\n";
        return;
    }
}

Node* LinkedList::nodeAddr(int pos) {
    if (!head) {
        std::cout << "\nList Empty\n";
        return nullptr;
    }

    int count{};
    Node *curr = head;
    while (count < pos) {
        curr = curr->getNext();
        count++;
    }

    if (count == pos && curr != 0) {
        return curr;
    } else {
        return nullptr;
    }
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

    Node *node = linkedList.nodeAddr(3);
    // cout << node << '\n';
    // cout << node->getData() << '\n';

    linkedList.deleteNode(node);

    linkedList.display();
}
