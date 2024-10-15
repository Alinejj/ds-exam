
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack{
    private:
        Node* top;

    public:
        Stack(){
            top = nullptr;
        }
        
    void push(int value){
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout<<value<<" pushed to stack"<<endl;
    }

    void pop(){
        if(top == nullptr){
            cout<<"underflow"<<endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        cout<<temp->data<<" popped"<<endl;
        delete temp;
    }

    int peek(){
        if(top == nullptr){
            cout<<"underflow"<<endl;
            return -1;
        }
        return top->data;
    }
bool isEmpty(){
    return top == nullptr;
}

void display(){
    Node* temp = top;
    while (temp != nullptr){
        cout<<temp->data<< " ";
        temp = temp->next;
    }
    cout<<endl;
}

void SelectionSort(){
    if(top == nullptr) return;

    int size = 0;
    Node* temp = top;

    while(temp != nullptr){
        size++;
        temp = temp->next;
    }

    int* arr = new int[size];
    temp = top;

    for(int i = 0; i<size; i++){
        arr[i] = temp->data;
        temp = temp->next;
    }

    for(int i = 0; i< size -1; i++){
        int iMin = i;
        for(int j = i+1; j < size; j++){
            if(arr[j] < arr[iMin]){
                iMin = j;
            }
        }
            if(iMin != i){
                int temp = arr[i];
                arr[i] = arr[iMin];
                arr[iMin] = temp;
            }
    }

    top = nullptr;
    for(int i = size -1; i>= 0; i--){
        push(arr[i]);
    }
    delete[] arr;
}

void BubbleSort(){
    if(top == nullptr) return;

    int size = 0;
    Node* temp = top;

    while(temp!= nullptr){
        size++;
        temp = temp->next;
    }

    int* arr = new int[size];
    temp = top;
    for(int i = 0; i <size; i++){
        arr[i] = temp->data;
        temp = temp->next;
    }

    for(int k = 1; k <size; k++){
        int flag = 0;
        for (int i = 0; i<size -1 - k; i++){
            if(arr[i] > arr[i+1]){
                int temp = arr[i];
                arr[i] = arr[ i+1];
                arr[i+1] = temp;
                flag = 1;
            }
        }
        if(flag == 0) {
            break;
        }
    }

    top = nullptr;
    for(int i = size - 1; i >= 0; i--) {
        push(arr[i]);
    }
    delete[] arr;
}

void InsertionSort(){
    if(top == nullptr) return;

    int size = 0;
    Node* temp = top;
    while(temp != nullptr){
        size++;
        temp = temp->next;
    }

    int* arr = new int[size];
    temp = top;
    for(int i = 0; i<size; i++){
        arr[i] = temp->data;
        temp = temp->next;
    }

    for(int i = 1; i<size; i++){
        int value = arr[i];
        int hole = i;
        while (hole > 0 && arr[hole-1] > value){
            arr[hole] = arr[hole - 1];
            hole = hole-1;

        }
        arr[hole] = value;
    }

    top = nullptr;
    for(int i = size - 1; i >= 0; i--){
        push(arr[i]);
    }

    delete[] arr;
}


};



int main(){
    Stack newStack;

    newStack.push(5);
    newStack.push(2);
    newStack.push(3);
    newStack.pop();
    newStack.push(4);

    cout<<"Stack before sorting: ";
    newStack.display();
    cout<<endl;

    newStack.SelectionSort();
    cout<<"Stack after sorting using selection sort: ";
    newStack.display();
    cout<<endl;

     newStack.BubbleSort();
    cout<<"Stack after sorting using bubble sort: ";
    newStack.display();
    cout<<endl;

    newStack.InsertionSort();
    cout<<"Stack after sorting using insertion sort: ";
    newStack.display();
    cout<<endl;

    return 0;


}