#include <iostream>
using namespace std;

class Node {
public:
    Node * pre, * next;
    int data;
    Node(const int &_data) {
        data = _data;
        next = NULL;
        pre = NULL;
    }
};

class LinkedList {
private:
    Node * head;
public:
    LinkedList() {
        head = NULL;
    }
    ~LinkedList() {
        if (head == NULL) {
            return;
        }
        Node * current_node = head -> next;
        head -> next = NULL;
        current_node -> pre = NULL;
        while (current_node != NULL) {
            Node * delete_node = current_node;
            current_node = current_node -> next;
            delete delete_node;
        }
    }
    void insert(Node *node, int index) {
        if (head == NULL) {
            if (index != 0) {
                return;
            }
            head = node;
            head -> next = head;
            return;
        }
        if (index == 0) {
            node -> next = head -> next;
            head -> next = node;
            return;
        }
        Node * current_node = head -> next;
        int count = 0;
        while (current_node  != head && count < index - 1) {
            current_node = current_node->next;
            count++;
        }
        if (count == index - 1) {
            node->next = current_node->next;
            current_node->next = node;
        }
        if (node == head -> next) {
            head = node;
        }
    }
    void dualOutput(const int &value) {
        if (head == NULL) {
            return;
        }
        Node * current_node = head;
        while (current_node -> data != value) {
            current_node = current_node -> next;
        }
        if (current_node -> data == value) {
            Node * end_node = current_node -> next;
            while (current_node -> pre != end_node) {
                cout << current_node -> data << " ";
                current_node = current_node -> pre;
            }
            cout << current_node -> data << " ";
            cout << end_node -> data << endl;
        }
    }
    void dualDirection() {
        if (head == NULL) {
            return;
        }
        Node * current_node = head -> next;
        while (current_node != head) {
            current_node -> next -> pre = current_node;
            current_node = current_node -> next;
        }
        head -> next -> pre = head;
    }
    void output() {
        if (head == NULL) {
            return;
        }
        Node * current_node = head -> next;
        cout << current_node -> data;
        while (current_node -> next != head -> next) {
            current_node = current_node -> next;
            cout << " " << current_node -> data;
        }
        cout << endl;
    }
    void reverseOutput() {
        if (head == NULL) {
            return;
        }
        Node * current_node = head;
        cout << current_node -> data;
        while (current_node -> pre != head) {
            current_node = current_node -> pre;
            cout << " " << current_node -> data;
        }
        cout << endl;
    }
};

int main() {
    LinkedList linkedlist;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        auto * node = new Node(num);
        linkedlist.insert(node, i);
        //linkedlist.output();
    }

    int key;
    cin >> key;
    linkedlist.dualDirection();
    //linkedlist.reverseOutput();
    linkedlist.dualOutput(key);

    return 0;
}
