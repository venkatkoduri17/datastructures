#include<iostream>
using namespace std;

void printArray(int A[], int size){
    int i = 0;
    while(i < size){
        cout << " " << A[i];
        i++;
    }
    cout << endl;
    return;

}

void swap(int* i, int* j){
    int temp = (*i);
    *i = *j;
    *j = temp;

    return;
}

int partition(int A[], int l, int h){

    // cout << endl << "Partition called with l : " << l << " to h : " << h;

    int pivot = A[h];
    int i = l-1;
    int j = h;

    // cout << endl << "Pivot : " << pivot;
    while(i < j){
        do{
            j--;
        }while(A[j] > pivot && i < j);

        do{
            i++;
        }while(A[i] < pivot && i < j);

        // cout << endl << "Before swap i : " << i << " j : " << j;
        if(i < j){
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[j+1], &A[h]);    
    return j+1;
    
}

void quickSort(int A[], int l, int h){

    // cout << endl << "\n\n\nquickSort called with l : " << l << " and h : " << h;
    if(l < h){
        // cout << endl << "It will call the partition function ";
        int p = partition(A, l, h);
        // cout << endl << "Partition value is : " << p;
        quickSort(A, l, p-1);
        quickSort(A, p+1, h);

    }else{
        // cout << endl << "Invalid values of l and h --- l : " << l << " h : " << h;
    }
    return;    
}

int main(){
    int A[] = {1, 12, 5, 17, 19, 7, 9, 120, -1, 56, -26, -290, 68, 457, 6, 91, 102};
    int size = sizeof(A)/sizeof(A[0]);

    cout << endl << "Array Before sorting : " ;
    printArray(A, size);

    quickSort(A, 0, size-1);

    cout << endl << "Array After sorting : " ;
    printArray(A, size);

}