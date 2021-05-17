#include <iostream>

class Node {
    public:
        Node(int val) : data{val} {}
        int getData() { return data; }
        void setNext(Node *node) { next = node; }
        Node *getNext() { return next; }

    private:
        int data{};
        Node* next{};
};

class LinkedList {
    public:
        void addVal(int val);
        void display();
        Node *getHead() { return head; }
        void setHead(Node *node) { head = node; }

    private:
        Node* head{};
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

LinkedList addToList(LinkedList list, int val) {
    if (list.getHead() == nullptr) {
        std::cout << "\nNo List To Add To\n";
        exit;
    }

    LinkedList newList{};
    Node *head = list.getHead();
    newList.setHead(head);

    newList.addVal(val);

    return newList;
}

Node* isIntersecting(LinkedList list1, LinkedList list2) {
    Node* 
}

int main() {
    LinkedList linkedList1{};
    LinkedList linkedList2{};
    int val{};

    while (std::cin>>val) {
        linkedList1.addVal(val);
        linkedList2.addVal(val);
    }

    linkedList1.display();
    linkedList2.display();

    LinkedList newList = addToList(linkedList1, 10);

    newList.display();

    std::cout << isIntersecting(linkedList1, newList);
    std::cout << isIntersecting(linkedList2, newList);
}