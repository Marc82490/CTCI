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
        void addValToEnd(int val);
        void display();
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

void LinkedList::display() {
    if (!head) {
        std::cout << "\nList Empty\n";
    }

    std::cout << '\n';
    Node *curr = head;
    while (curr->getNext() != nullptr) {
        std::cout << curr->getData() << "->";
        curr = curr->getNext();
    }
    std::cout << curr->getData() << '\n';
}

LinkedList sumLists(Node* list1, Node* list2) {
    LinkedList sumList{};

    int carry{};

    while (list1->getNext() != nullptr || list2->getNext() != nullptr || carry != 0) {
        int sum{};
        sum = list1->getData() + list2->getData() + carry;
        carry = sum / 10;
        sum %= 10;
        sumList.addValToEnd(sum);
        if (list1->getNext() == nullptr) {
            Node *newNode = new Node(0);
            list1->setNext(newNode);
        }
        if (list2->getNext() == nullptr) {
            Node *newNode = new Node(0);
            list2->setNext(newNode);
        }
        list1 = list1->getNext();
        list2 = list2->getNext();
    }

    return sumList;
}

int main() {
    LinkedList linkedList1{};
    LinkedList linkedList2{};
    int val1{};
    int val2{};

    while (std::cin>>val1>>val2) {
        linkedList1.addVal(val1);
        linkedList2.addVal(val2);
    }

    linkedList1.display();
    linkedList2.display();

    Node *list1 = linkedList1.getHead();
    Node *list2 = linkedList2.getHead();

    LinkedList sumList = sumLists(list1, list2);

    sumList.display();
}