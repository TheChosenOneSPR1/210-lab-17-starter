#include <iostream>
#include <cstdlib>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

void output(Node *);
void output(Node * hd);
void addFront(Node *&head, float val);
void addBack(Node *&head, float val);
void deleteNode(Node *&head, int pos);
void insertNode(Node *&head, int pos, float);
void deleteList(Node *&head);

int main() {
    Node *head = nullptr;

    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        addFront(head, tmp_val);
    }
    // deleting a node
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;
    deleteNode(head, entry);
    cout << "List after deletion " << entry << ":" << endl;
    output(head);

    cout << "After which node do you want to insert 10000? " << endl;
    output(head);
    cout << "Choice --> ";
    cin >> entry;
    insertNode(head, entry, 10000);   
    cout << "List after insertion:" << endl;
    output(head);

    cout << "Adding 555 to the back..." << endl;
    addBack(head, 555);
    output(head);

    cout << "Deleting everything..." << endl;
    deleteList(head); 
    output(head);

    return 0;
}

void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

void addFront(Node *&head, float val) {
    Node *newNode = new Node;
    newNode->value = val;
    newNode->next = head;
    head = newNode;
}

void deleteNode(Node *&head, int pos) {
    if (!head || pos < 1) return;

    Node *current = head;
    if (pos == 1) {
        head = head->next;
        delete current;
        return;
    }

     Node *prev = nullptr;
    for (int i = 1; i < pos && current; i++) {
        prev = current;
        current = current->next;
    }
    if (current) {
        prev->next = current->next;
        delete current;
    }
}

void insertNode(Node *&head, int pos, float val) {
    if (!head) return; 

    Node *current = head;
    for(int i = 1; i < pos && current; i++) {
        current = current->next;
    }
    if (!current) return;

    Node *newNode = new Node;
    newNode->value = val;
    newNode->next = current->next;
    current->next = newNode;
}

void addBack(Node *&head, float val) {
    Node *newNode = new Node;
    newNode->value = val;
    newNode->next = nullptr;

    if (!head) {
        head = newNode;
        return;
    }

    Node *t = head;
    while (t->next) {
        t = t->next;
    }
    t->next = newNode;
}
void deleteList(Node *&head) {
    Node *current = head;
    while (current) {
        Node *nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
}
