#include <iostream>
#include <set>

using namespace std;

class Node {
    public:
        Node(int val) : data{val} {}
        void setNext(Node *node) { next = node; }
        int getData() { return data; }
        Node* getNext() { 
            if (next) {
                return next; 
            } else {
                return nullptr;
            }
        }

    private:
        int data{};
        Node *next{};
};

class LinkedList {
    public:
        LinkedList() {}
        void removeDupes();
        void addVal(int val);
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

    Node *currHead = head;
    newNode->setNext(head);
    head = newNode;
    // while (curr->getNext() != nullptr) {
    //     curr = curr->getNext();
    // }
    // curr->setNext(newNode);
}

void LinkedList::removeDupes() {
    set<int> dataSet;

    if (!head) {
        cout << "\nNothing to remove\n";
    }

    Node *curr = head;
    Node *prev = NULL;
    // BAD ATTEMPT. WORKED BUT INEFFICIENT
    // while (curr != nullptr) {
    //     int key = curr->getData();
    //     dataDict.insert({key, dataDict[key]+1});
    //     curr = curr->getNext();
    // }

    // head = nullptr;

    // for (pair<int, int> element : dataDict)
    // {
    //     addVal(element.first);
    // }
    while (curr != nullptr) {
        auto result = dataSet.find(curr->getData());
        if (result != dataSet.end()) {
            prev->setNext(curr->getNext());
        } else {
            dataSet.insert(curr->getData());
            prev = curr;
        }
        curr = curr->getNext();
    }
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
    cout << curr->getData();
}

int main() {
    LinkedList linkedList{};

    int val;
    while (cin>>val) {
        linkedList.addVal(val);
    }

    linkedList.display();

    linkedList.removeDupes();

    linkedList.display();
}