#include <iostream>

using namespace std;

//node struct
struct Node{
    int data;
    Node* next;
};


//linked list class
class LinkedList{
    Node * head;

    public:
    LinkedList(){
        head = nullptr;
    }

    //insert node at beginning
    void insertAtBeginning(int value){
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    //insert at the end
    void insertAtEnd(int value){
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if(head == nullptr){
            head = newNode;
            return;
        }

        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }


    //insert a node at a specific pos
    void insertAtPosition(int value, int position){
        if(position < 0){
            cout<<"Invalid position"<<endl;
            return;
        }
        Node* newNode = new Node();
        newNode->data = value;

        if(position == 0){
            newNode->next = head;
            head = newNode;
            return;
        }

        Node *temp = head;
        for(int i = 0; temp != nullptr && i< position-1; i++){
            temp = temp->next;
        }

        if(temp == nullptr){
            cout<<"Position out of bounds"<<endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    //delete a node within a given val
    void deleteNode(int value){
        if(head == nullptr){
            cout<<"List is empty"<<endl;
            return;
        }

        if(head->data == value){
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while(temp->next != nullptr && temp->next->data != value){
            temp=temp->next;
        }

        if(temp->next == nullptr){
            cout<<"Node not found"<<endl;
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    //search for a node
    bool search(int value){
        Node* temp = head;
        while(temp != nullptr){
            if(temp->data == value){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    //display list
    void display(){
        if(head == nullptr){
            cout<<"List is empty"<<endl;
            return;
        }

        Node* temp = head;
        while(temp != nullptr){
            cout<<temp->data << " -> ";
            temp= temp->next;
        }
        cout<<"NULL"<<endl;
    }

    //get size of list
    int getSize(){
        int size = 0;
        Node* temp = head;
        while(temp != nullptr){
            size++;
            temp = temp->next;
        }
        return size;
    }

    void bubbleSort() {
        if (head == nullptr){
            return;
        }

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


    void insertionSort() {
        if (head == nullptr) return;

        Node* sorted = nullptr;

        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;

            if (sorted == nullptr || sorted->data >= current->data) {
                current->next = sorted;
                sorted = current;
            } else {
                Node* temp = sorted;
                while (temp->next != nullptr && temp->next->data < current->data) {
                    temp = temp->next;
                }
                current->next = temp->next;
                temp->next = current;
            }
            current = next;
        }

        head = sorted;
    }


};

int main() {
    LinkedList list;

    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    cout<<"Linked list: ";
    list.display();

    list.insertAtPosition(25, 2);
    cout<<"Linked list after inserting 25 at pos. 2: ";
    list.display();

    cout<<"Size of list: "<<list.getSize()<<endl;

    cout<<"Searching for 20: "<<list.search(20)<<endl;

    list.deleteNode(20);
    cout << "Linked List after deleting 20: ";
    list.display();


    list.bubbleSort();
    cout << "Linked List after bubble sort: ";
    list.display();

    list.selectionSort();
    cout << "Linked List after selection sort: ";
    list.display();

    list.insertionSort();
    cout << "Linked List after insertion sort: ";
    list.display();

    return 0;
}