#include <iostream>

using namespace std;

class Node {
    public:
        int getData() { return data; }
        Node* getNext() {return next;}
        void setNext(Node *node) { next = node; }

    private:
        int data{};
        Node *next{};
};

class LinkedList {
    public:
        void addVal(int val);
        void partition(int val);
        void display();

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

void LinkedList::partition(int val) {
    
}

void LinkedList::display() {
    if (!head) {
        cout << "\nList Empty\n";
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
}