#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Doubly Linked List class
class DoublyLinkedList {
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    // Insert a node at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        newNode->prev = nullptr;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
    }

    // Insert a node at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            newNode->prev = nullptr;
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    // Insert a node at a specific position
    void insertAtPosition(int value, int position) {
        if (position < 0) {
            cout << "Invalid position" << endl;
            return;
        }

        Node* newNode = new Node();
        newNode->data = value;

        if (position == 0) {
            newNode->next = head;
            newNode->prev = nullptr;
            if (head != nullptr) {
                head->prev = newNode;
            }
            head = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 0; temp != nullptr && i < position - 1; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Position out of bounds" << endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }

    // Delete a node with a given value
    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr && temp->data != value) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node not found" << endl;
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
    }

    // Search for a node with a given value
    bool search(int value) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Display the doubly linked list
    void display() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Get the size of the doubly linked list
    int getSize() {
        int size = 0;
        Node* temp = head;
        while (temp != nullptr) {
            size++;
            temp = temp->next;
        }
        return size;
    }

    // Bubble sort the doubly linked list
    void bubbleSort() {
        if (head == nullptr) return;

        bool swapped;
        Node* ptr1;
        Node* lptr = nullptr;

        do {
            swapped = false;
            ptr1 = head;

            while (ptr1->next != lptr) {
                if (ptr1->data > ptr1->next->data) {
                    swap(ptr1->data, ptr1->next->data);
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
    }

    // Selection sort the doubly linked list
    void selectionSort() {
        if (head == nullptr) return;

        Node* temp = head;

        while (temp) {
            Node* min = temp;
            Node* r = temp->next;

            while (r) {
                if (min->data > r->data) {
                    min = r;
                }
                r = r->next;
            }

            // Swap data
            int x = temp->data;
            temp->data = min->data;
            min->data = x;
            temp = temp->next;
        }
    }

    // Insertion sort the doubly linked list
    void insertionSort() {
        if (head == nullptr) return;

        Node* sorted = nullptr;

        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;

            if (sorted == nullptr || sorted->data >= current->data) {
                current->next = sorted;
                if (sorted != nullptr) {
                    sorted->prev = current;
                }
                sorted = current;
                sorted->prev = nullptr;
            } else {
                Node* temp = sorted;
                while (temp->next != nullptr && temp->next->data < current->data) {
                    temp = temp->next;
                }
                current->next = temp->next;
                if (temp->next != nullptr) {
                    temp->next->prev = current;
                }
                temp->next = current;
                current->prev = temp;
            }

            current = next;
        }

        head = sorted;
    }
};

int main() {
    DoublyLinkedList list;

    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    cout << "Doubly Linked List: ";
    list.display();

    list.insertAtPosition(25, 2);
    cout << "Doubly Linked List after inserting 25 at position 2: ";
    list.display();

    cout << "Size of the list: " << list.getSize() << endl;

    cout << "Searching for 20: " << (list.search(20) ? "Found" : "Not Found") << endl;
    cout << "Searching for 50: " << (list.search(50) ? "Found" : "Not Found") << endl;

    list.deleteNode(20);
    cout << "Doubly Linked List after deleting 20: ";
    list.display();

    list.deleteNode(50);
    cout << "Doubly Linked List after attempting to delete 50: ";
    list.display();

    list.bubbleSort();
    cout << "Doubly Linked List after bubble sort: ";
    list.display();

    list.selectionSort();
    cout << "Doubly Linked List after selection sort: ";
    list.display();

    list.insertionSort();
    cout << "Doubly Linked List after insertion sort: ";
    list.display();

    return 0;
}
