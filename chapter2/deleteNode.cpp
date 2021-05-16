#include <iostream>

using namespace std;

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
        cout << "\nNode Invalid\n";
        return;
    }

    if (!head) {
        cout << "\nList Empty\n";
        return;
    }

    if (node->getNext() != nullptr) {
        Node *next = node->getNext();
        node->setData(next->getData());
        node->setNext(next->getNext());
    } else {
        cout << "\nNode at end of list, cannot remove\n";
        return;
    }
}

Node* LinkedList::nodeAddr(int pos) {
    if (!head) {
        cout << "\nList Empty\n";
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
        cout << "\nList Empty\n";
        return;
    }

    cout << '\n';
    Node *curr = head;
    while (curr->getNext() != nullptr) {
        cout << curr->getData() << "->";
        curr = curr->getNext();
    }
    cout << curr->getData() << '\n';
}

int main() {
    LinkedList linkedList{};
    int val{};

    while (cin>>val) {
        linkedList.addVal(val);
    }

    linkedList.display();

    Node *node = linkedList.nodeAddr(3);
    // cout << node << '\n';
    // cout << node->getData() << '\n';

    linkedList.deleteNode(node);

    linkedList.display();
}
