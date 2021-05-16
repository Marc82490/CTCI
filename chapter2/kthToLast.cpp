#include <iostream>

// using namespace std;

class Node {
    public:
        Node(int val) : data{val} {}
        int getData() { return data; }
        void setNext(Node *node) { next = node; }
        Node *getNext() { return next; }
        //     if (next) {
        //         return next; 
        //     } else {
        //         return nullptr;
        //     }
        // }

    private:
        int data{};
        Node *next{};
};

class LinkedList {
    public:
        LinkedList() {}
        void addVal(int val);
        int kthToLast(int k);
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

    // Node *curr = head;
    newNode->setNext(head);
    head = newNode;
    // while (curr->getNext() != nullptr) {
    //     curr = curr->getNext();
    // }
    // curr->setNext(newNode);
}

int LinkedList::kthToLast(int k) {
    if (!head) {
        std::cout << "\nList Empty\n";
    }

    Node *first = head;
    Node *second = head;

    for (int i{}; i < k; i++)
    {
        if (first->getNext() != nullptr) {
            first = first->getNext();
        }
    }

    while (first->getNext() != nullptr) {
        first = first->getNext();
        second = second->getNext();
    }

    return second->getData();
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

int main() {
    LinkedList linkedList{};
    int val;
    while (std::cin>>val) {
        linkedList.addVal(val);
    }

    linkedList.display();

    std::cout << '\n' << linkedList.kthToLast(0);
    std::cout << '\n' << linkedList.kthToLast(1);
    std::cout << '\n' << linkedList.kthToLast(2);
    std::cout << '\n' << linkedList.kthToLast(3);
}