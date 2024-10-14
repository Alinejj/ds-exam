#include <iostream>

using namespace std;

class Queue{
    int front;
    int rear;
    int capacity;
    int *arr;

    public :
    Queue(int size){
        this->capacity = size;
        this->front = -1;
        this->rear = -1;
        this->arr = new int[this->capacity];
    }

    //check if queue is empty
    bool isEmpty(){
        return (front == -1);
    }

    //check if queue is full
    bool isFull(){
        return ((rear + 1) % capacity == front);
    }

    //add element to queue
    void enqueue(int value){
        if(isFull()){
            cout<<"OVERFLOW"<<endl;
            return;
        }
        if(isEmpty()){
            front = rear = 0;
            cout<<"Queue is empty"<<endl;
        }
        else{
            //increment rear from -1 into queue
            rear = (rear + 1) % capacity;
        }
        arr[rear] = value;
    }

    //remove element from queue
    int dequeue(){
        if(isEmpty()){
            cout<<"UNDERFLOW"<<endl;
            return -1;
        }

        int value = arr[front];
        if(front == rear){
            front = rear = -1;
        }
        else{
            front = (front + 1) % capacity;
        }
        return value;
    }

    int peek(){
        if(isEmpty()){
            cout<<"No item to return"<<endl;
            return -1;
        }
        return arr[front];
    }

    void display(){
        if(isEmpty()){
            cout<<"No item to return"<<endl;
            return;
        }

        int i = front;
        while(true){
            cout<<arr[i]<<" ";
            if(i == rear){
                break;
            }
            i = (i + 1) % capacity;
        }
        cout<<endl;
    }

    int size(){
        return capacity;
    }

    int get(int index){
        return this->arr[index];
    }
    void set(int index, int value){
        this->arr[index] = value;
    }


};

void BubbleSortQueue(Queue &q){
    int n = q.size();

    for(int k =1; k < n; k++){
        int flag = 0;
        for(int i = 0; i< n - k; i++){
            if(q.get(i) > q.get(i+1)){
                int temp = q.get(i);
                q.set(i, q.get(i+1));
                q.set(i+1, temp);
                flag = 1;
            }
        }
        if(flag == 0){
            break;
        }
    }
}

void InsertionsortQueue(Queue &q){
    int n = q.size();

    for(int i = 1; i<n; i++){
        int key = q.get(i);
        int j = i - 1;
        while(j >= 0 && q.get(j) > key){
            q.set(j+1, q.get(j));
            j = j-1;
        }
        q.set(j+1, key);

    }
}

void SelectionSortQueue(Queue &q){
    int n = q.size();
    for(int i = 0; i < n-1; i++){
        int iMin = i;
        for (int j = i+1; j < n; j++){
            if(q.get(j) < q.get(iMin)){
                iMin = j;
            }
            if(iMin != i){
            int temp =q.get(i);
            q.set(i, q.get(iMin));
            q.set(iMin, temp);
            }
            
        }
    }
}


int main(){

    Queue q(5);

    q.enqueue(20);
    q.enqueue(6);
    q.enqueue(60);
    q.enqueue(40);
    q.enqueue(50);

    cout<<"Queue after enqueueing 5 elements: ";
    q.display();

    cout<<"Dequeued element: "<<q.dequeue()<<endl;
    cout<<"Queue after dequeueing an element: ";
    q.display();


    BubbleSortQueue(q);
    cout<<"Queue after using bubble sort: ";
    for(int i = 0; i < q.size(); i++){
        cout<<q.get(i)<<" ";
    }
    cout<<endl;

    InsertionsortQueue(q);
    cout<<"Queue after using insertion sort: ";
    for(int i = 0; i < q.size(); i++){
        cout<<q.get(i)<<" ";
    }
    cout<<endl;


    SelectionSortQueue(q);
    cout<<"Queue after using selection sort: ";
    for(int i = 0; i < q.size(); i++){
        cout<<q.get(i)<<" ";
    }
    cout<<endl;
}