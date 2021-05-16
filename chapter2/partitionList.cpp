#include <iostream>
#include <vector>
#include <algorithm>

// using namespace std;

class Node {
    public:
        Node(int val) : data{val} {} 
        int getData() { return data; }
        Node* getNext() {return next;}
        void setNext(Node *node) { next = node; }
        void setData(int val) { data = val; }

    private:
        int data{};
        Node *next{};
};

class LinkedList {
    public:
        void addVal(int val);
        Node* partition(int val);
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

/* BAD ATTEMPT */
// void LinkedList::partition(int val) {
//     std::vector<int> vals{};

//     Node *curr = head;
//     while (curr != nullptr) {
//         vals.push_back(curr->getData());
//         curr = curr->getNext();
//     }

//     std::sort(vals.begin(), vals.end());

//     curr = head;
//     for (int val : vals) {
//         curr->setData(val);
//         curr = curr->getNext();
//     }
// }

/* ANSWER FROM THE BOOK */
Node* LinkedList::partition(int val) {
    Node *leftHead = nullptr;
    Node *leftTail = nullptr;
    Node *rightHead = nullptr;
    Node *rightTail = nullptr;

    Node *curr = head;
    while (curr != nullptr) {
        Node *next = curr->getNext();
        curr->setNext(nullptr);

        if (curr->getData() < val) {
            if (leftHead == nullptr) {
                leftHead = curr;
                leftTail = leftHead;
            } else {
                leftTail->setNext(curr);
                leftTail = curr;
            }
        } else {
            if (rightHead == nullptr) {
                rightHead = curr;
                rightTail = rightHead;
            } else {
                rightTail->setNext(curr);
                rightTail = curr;
            }
        }
        curr = next;
    }

    if (leftHead == nullptr) {
        return rightHead;
    }

    leftTail->setNext(rightHead);
    return leftHead;
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
    int val{};

    while (std::cin>>val) {
        linkedList.addVal(val);
    }

    linkedList.display();

    linkedList.partition(5);

    linkedList.display();
}