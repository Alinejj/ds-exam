#include <iostream>

using namespace std;

void SelectionSort( int A[], int n){
    for (int i = 0; i < n-1; i++){
        int iMin = i;
        for (int j = i+1; j < n; j++){
            if(A[j] < A[iMin]){
                iMin = j;
            }
            if(iMin != i){
            int temp = A[i];
            A[i] = A[iMin];
            A[iMin] = temp;
            }
            
        }
    }
}

int main(){

int A[] = {1,4,5,6,7,3,2,8};

SelectionSort(A,8);

for(int i=0; i<8; i++){
    cout<<A[i]<<" ";
}

return 0;
}