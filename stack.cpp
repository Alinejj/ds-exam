

#include <iostream>

using namespace std;

class Stack{

    int totalSize;
    int currentSize;
    int  * arr;

    public:

    Stack(int size){
        this->totalSize = size;
        this->currentSize = 0;
        this->arr = new int[this->totalSize];

    }
    //checks if the stack is empty
    bool isEmpty(){
        return this->currentSize == 0;
    }

    //checks if the stack is full
    bool isFull(){
        return this->currentSize == this->totalSize;

    }

    void push(int value){
        //check if stack is full before pushing
        if(isFull()){
            cout<<"OVERFLOW"<<endl;
        }
        else {
            //push the value into stack and increment currsize
            this->arr[this->currentSize] = value;
            this->currentSize++;

        }
    }

    int pop(){
        //check if stack is empty 
        if(isEmpty()){
            cout<<"UNDERFLOW"<<endl;
            //return -1 if stack is empty
            return -1;
        }
        else{
            //decrement currsize in order to pop
            this->currentSize--;
            return this->arr[this->currentSize];
        }
    }

    int peek(){
        //check if stack is empty
        if(isEmpty()){
            cout<<"No item to return"<<endl;
            return -1;
        }
        else {
            //returns the element
            return this->arr[this->currentSize];
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Stack elements: ";
            for (int i = 0; i < currentSize; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
    
    //return size of stack
    int size(){
        return this->currentSize;
    }

    int get(int index){
        return this->arr[index];
    }
    void set(int index, int value){
        this->arr[index] = value;
    }

    
};

void bubbleSortStack(Stack &s){
        int n = s.size();

        for(int k = 1; k < n; k++){
        int flag = 0;
        for (int i = 0; i<n-k; i++){
            if (s.get(i) > s.get(i+1)){
                //swap
                int temp = s.get(i);
                s.set(i, s.get(i+1));
                s.set(i+1, temp);
                flag = 1;
            }
        }
        if(flag == 0){
            break;
        }
    }

  }

void insertionSortStack(Stack &s){
    int n = s.size();

    for (int i = 0; i < n; i++){
        int key = s.get(i);
        int j = i - 1;

        while ( j >= 0 && s.get(j)>key){
          s.set(j+1, s.get(j));
          j = j - 1;
        }
        s.set(j+1, key);
    }
    
}

void selectionSortStack(Stack &s){
int n = s.size();

for (int i = 0; i < n-1; i++){
        int iMin = i;
        for (int j = i+1; j < n; j++){
            if(s.get(j) < s.get(iMin)){
                iMin = j;
            }
            if(iMin != i){
        
             int temp = s.get(i);
                s.set(i, s.get(iMin));
                s.set(iMin, temp);
            }
            
        }
    }
}

int main(){
    //create a stack of size 3
    Stack newStack(7);

    newStack.push(5);
    newStack.push(2);
    newStack.push(3);
    newStack.pop();
    newStack.push(4);

    cout<<"Stack before sorting: ";
    for (int i = 0; i<newStack.size(); i++){
        cout<<newStack.get(i)<<" ";
    }
    cout<<endl;



    bubbleSortStack(newStack);
    cout<<"Stack after sorting using bubble sort: ";
    for(int i = 0; i< newStack.size(); i++){
        cout<<newStack.get(i)<<" ";
    }
    cout<<endl;


    insertionSortStack(newStack);
    cout<<"Stack after sorting using insertion sort: ";
    for(int i = 0; i< newStack.size(); i++){
        cout<<newStack.get(i)<<" ";
    }
    cout<<endl;



    selectionSortStack(newStack);
    cout<<"Stack after sorting using selection sort: ";
    for(int i = 0; i< newStack.size(); i++){
        cout<<newStack.get(i)<<" ";
    }
    cout<<endl;

    return 0;
}