#include <iostream>

// using namespace std;

class Node {
    /* Node Class
    Contains a data member and a pointer to the next node.
    Methods: getData, setNext, getNext.
    */
    public:
        Node(int data) : data{data} {}
        int getData() { return data; }
        void setNext(Node* node) { next = node; }
        Node* getNext() { 
            if (next == NULL) {
                return nullptr;
            }
            else {
                return next;
            }
        }

    private:
        int data{};
        Node *next{};
};

class LinkedList {
    /* Linked List Class
    Contains a pointer to the head node.
    Methods: addVal, remove, display, contains.
    */
    public:
        LinkedList() : head{} {}
        // LinkedList(Node& head) : head{&head} {}
        void addVal(int val);
        void remove(int val);
        bool contains(int val);
        void insert(int val, int pos);
        void reverse();
        void display();

    private:
        Node *head{};
};

void LinkedList::addVal(int val) {
    /* Adds a new value to the linked list */
    // Allocate storage for a new node object
    Node *newNode = new Node(val);
    
    // Handle if the list is currently empty
    if (!head) {
        head = newNode;
        return;
    }

    // Otherwise, loop through the list until you get to the end, then add the new node
    Node* n = head;
    while (n->getNext() != nullptr) {
        // cout << n->getData() << '\n';
        n = n->getNext();
    }
    n->setNext(newNode);
    // return;
}

void LinkedList::remove(int val) {
    /* Removes a value from the linked list */
    // Handle if the list is currently empty
    if (!head) {
        std::cout << "\nList empty, nothing to remove\n";
    }

    // Keep track of current and previous positions in the list
    Node *curr = head;
    Node *prev = NULL;

    // Move down the list until you either reach the end or get to the value
    while (curr->getData() != val) {
        if (curr->getNext() != nullptr) {
            prev = curr;
            curr = curr->getNext();
        }
        else {
            std::cout << "\nNode not found\n";
            return;
        }
    }
    // If we've seen the value, slice it out of the list by pointing prev to point to current's next value
    prev->setNext(curr->getNext());
    delete curr;
}

bool LinkedList::contains(int val) {
    /* Checks whether the list contains a given value */
    // Handle if the list is currently empty
    if (!head) {
        std::cout << "\nList empty, contains nothing\n";
    }

    // Move down the list until either reach the end or get to the value
    Node *n = head;
    while (n->getData() != val) {
        if (n->getNext() != nullptr) {
            n = n->getNext();
        }
        // Reach end of the list without seeing value, value not in list
        else {
            return false;
        }
    }
    // If we've seen the value, acknowledge 
    return true;
}

void LinkedList::insert(int val, int pos) {
    /* Inserts a val into a linked list at a given position */
    // Handle if the list is currently empty
    if (!head) {
        addVal(val);
        return;
    }

    // Allocate space for the new node
    Node *newNode = new Node(val);

    // Move down the list until you reach the point where the the value is to be inserted
    Node *curr = head;
    Node *prev = NULL;
    int counter{};
    // Stop 1 position short
    while ((counter < pos-1) && (curr->getNext() != nullptr)) {
        counter++;
        prev = curr;
        curr = curr->getNext();
    }
    // Insert the new node into the list
    newNode->setNext(curr->getNext());
    curr->setNext(newNode);
}

void LinkedList::reverse() {
    /* Reverses a linked list */
    // Handle if the list is currently empty
    if (!head) {
        std::cout << "\nList empty, nothing to reverse\n";
    }

    // Keep track of where we are
    Node *curr = head;
    Node *prev = NULL;
    Node *temp = NULL;

    // Move down the list, flipping pointers to go in the opposite direction
    while (curr != nullptr) {
        temp = curr->getNext();
        curr->setNext(prev);
        prev = curr;
        curr = temp;
    }
    // Set the head to point to the old tail/new head
    head = prev;
}

void LinkedList::display() {
    /* Print out each value in the list */
    // Handle if the list is currently empty
    if (!head) {
        std::cout << "\nNo head\n";
        return;
    }

    // Move down the list and print out each value
    std::cout << '\n';
    Node *n = head;
    while (n->getNext() != NULL) {
        std::cout << n->getData() << "->";
        n = n->getNext();
    }
    // Print out the last value in the list
    std::cout << n->getData();
}

int main() {
    LinkedList linkedList{};
    int val{};

    // cin >> val;

    // linkedList.insert(val, 6);
    linkedList.display();

    while (std::cin >> val)
    {
        linkedList.addVal(val);
    }

    linkedList.display();

    linkedList.remove(2);

    linkedList.display();

    std::cout << '\n' << linkedList.contains(2);

    std::cout << '\n' << linkedList.contains(3);

    linkedList.insert(10, 3);

    linkedList.display();

    linkedList.reverse();

    linkedList.display();
}