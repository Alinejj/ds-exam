#include <iostream>

using namespace std;

void InsertionSort(int A[], int n){
    for (int i = 1; i<n; i++){
        int value = A[i];
        int hole = i;
        while (hole > 0 && A[hole - 1] > value){
            A[hole] = A[hole-1];
            hole = hole - 1;
        }
        A[hole] = value;
    }
}

int main(){
    int A[] = {9,7,6,3,2,1,8};

    InsertionSort(A,7);

    for(int i = 0; i<7; i++){
        cout<<A[i]<<" ";
    }
    return 0;
}