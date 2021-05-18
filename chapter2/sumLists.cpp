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
        int getLen();

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

int getLen(Node* node) {
    if (!node) {
        return 0;
    }

    int count{};
    while (node != nullptr) {
        node = node->getNext();
        count++;
    }

    return count;
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

/* SOLUTION WHERE "1->2->3" REPRESENTS THE NUMBER 321 */
LinkedList sumLists(Node* list1, Node* list2) {
    LinkedList sumList{};

    int carry{};

    // Loop through both lists, adding up each pair of nodes, making sure to account for any carry from the last
    // set of additions. Append the sum to the new list and move to the next nodes.
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

/* HELPER FUNCTION FOR THE RECURSIVE sumListsReverse FUNCTION */
LinkedList sumListsReverseHelper(Node* curr1, Node* curr2, LinkedList sumList, int carry) {
    // Base Case: Reach the end of the list, return the built list.
    if (curr1 == nullptr || curr2 == nullptr) {
        return sumList;
    }

    // Recursive Case: Sum the pair of nodes plus any carry from the last addition, add it to the built list, and recurse.
    int sum = curr1->getData() + curr2->getData() + carry;
    carry = sum / 10;
    sum %= 10;
    sumList.addVal(sum);
    sumListsReverseHelper(curr1->getNext(), curr2->getNext(), sumList, carry);
}

/* SOLUTION WHERE "1->2->3" REPESENTS THE NUMBER 123 */
LinkedList sumListsReverse(LinkedList list1, LinkedList list2) {
    LinkedList sumList{};

    // Need to account for differences in the lengths of the lists, since 1234 + 567 has an implicit 0 in the thousands
    // place of 567.
    int len1 = list1.getLen();
    int len2 = list2.getLen();
    int maxLen = len1 > len2 ? len1 : len2;
    int minLen = len1 <= len2 ? len1 : len2;
    int count{};

    // Append 0s to which list is shorter in length, until the lengths are equal.
    while (count < (maxLen-minLen)) {
        if (len1 > len2) {
            list2.addVal(0);
        } else {
            list1.addVal(0);
        }
    }

    Node *list1Node = list1.getHead();
    Node *list2Node = list2.getHead();
    int carry{};

    // Recursively sum the nodes and build the resulting list.
    sumList = sumListsReverseHelper(list1Node, list2Node, sumList, carry);
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

    LinkedList sumListReverse = sumListsReverse(linkedList1, linkedList2);

    sumListReverse.display();
}