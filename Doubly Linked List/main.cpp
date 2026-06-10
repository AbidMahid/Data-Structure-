#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DList {
private:
    Node* head;

public:
    DList() {
        head = nullptr;
    }

    void insertFirst(int val) {
        Node* newNode = new Node(val);
        if (head != nullptr) {
            head->prev = newNode;
            newNode->next = head;
        }
        head = newNode;
        cout << val << " inserted at first\n";
    }

    void insertLast(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            cout << val << " inserted at last\n";
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        cout << val << " inserted at last\n";
    }

    void del(int val) {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        while (temp != nullptr && temp->data != val) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << val << " not found\n";
            return;
        }

        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next;
        }

        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }

        delete temp;
        cout << val << " deleted\n";
    }

    void showF() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        cout << "Forward: NULL <-> ";
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void showB() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        cout << "Backward: NULL <-> ";
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL\n";
    }
};

int main() {
    DList list;
    int choice, val;

    do {
        cout << "\n1. Insert First\n2. Insert Last\n3. Delete\n4. Show Forward\n5. Show Backward\n6. Exit\nChoice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                list.insertFirst(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                list.insertLast(val);
                break;
            case 3:
                cout << "Enter value to delete: ";
                cin >> val;
                list.del(val);
                break;
            case 4:
                list.showF();
                break;
            case 5:
                list.showB();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while(choice != 6);

    return 0;
}
