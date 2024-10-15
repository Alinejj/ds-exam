#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue{
    private:
        Node* front;
        Node* rear;
       
    public:
        Queue(){
            front = nullptr;
            rear = nullptr;
            
        }


    void enqueue(int value){
        Node* temp = new Node();
        temp->data = value;
        temp->next = nullptr;
        if(rear == nullptr){
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    void dequeue(){
        if(front == nullptr){
            cout<<"UNDERFLOW"<<endl;
            return ;
        }

        Node* temp = front;
        front = front->next;
        if(front == nullptr){
            rear == nullptr;
        }
        delete temp;
    }

    

    void display(){

        if(front == nullptr){
            cout<<"queue is empty"<<endl;
            return;
        }
        Node* temp = front;

        while(temp != nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;

            }
            cout<<endl;
        }
        
    

    void SelectionSort(){
        if(front == nullptr){
            return;
        }

        int size = 0;
        Node* temp = front;
        while(temp != nullptr){
            size++;
            temp = temp->next;
        }

        int* arr = new int[size];
        temp = front;

        for(int i = 0; i<size; i++){
            arr[i] = temp->data;
            temp = temp->next;
        }

        for(int i = 0; i<size -1; i++){
            int iMin = i;
            for(int j = i+1; j<size; j++){
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

         front = nullptr;
        rear = nullptr;
             for(int i = size-1; i>=0; i--){
              enqueue(arr[i]);
        }
        delete[] arr;
        



    }

};

int main(){
    Queue q;

    q.enqueue(5);
    q.enqueue(3);
    q.enqueue(8);
    q.enqueue(2);
    q.enqueue(1);

    cout<<"Current queue: ";
    q.display();


    q.dequeue();
    cout<<"queue after dequeue: ";
    q.display();

    q.SelectionSort();
    cout<<"queue after selection sort: ";
    q.display();

    return 0;

}