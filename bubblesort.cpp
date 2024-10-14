#include <iostream>

using namespace std;

void BubbleSort(int A[], int n){
    for(int k = 1; k < n; k++){
        int flag = 0;
        for (int i = 0; i<n-k; i++){
            if (A[i] > A[i+1]){
                int temp = A[i];
                A[i] = A[i+1];
                A[i+1] = temp;
                
                flag = 1;
            }
        }
        if(flag == 0){
            break;
        }
    }
}

int main(){
    int A[] = {1,2,8,7,9,4,5};

    BubbleSort(A,7);
    for(int i = 0; i<7; i++){
        cout<<A[i]<< " ";
    }
    return 0;
}