#include <iostream>
using namespace std;

void printArray(int a[ ],int size){
    for (int i = 0; i < size; i++){
        cout << a[i] << " ";
    }
}

void swap(int *a,int *b){ 
    int tmp = *a;
        *a = *b;
        *b = tmp;
}

void SelectionSort(int a[ ],int size){
    for(int i=0;i<size-1;i++){
        int min_idx = i;
        for(int j=i+1;j<size;j++){
            if(a[min_idx]>a[j]){
                min_idx = j;
            }
        }
            swap(&a[min_idx],&a[i]);
    }
}

int main()
{
    int num, a[1000], i;

    cout << "How many elements you wants to enter : ";
    cin >> num;

    cout << "Enter " << num << " elements...\n";
    for (i = 0; i < num; i++){
        cin >> a[i];
    }

    cout << "Unsorted array elements...\n";
    printArray(a,num);
    cout << endl;

    SelectionSort(a,num);
    cout << "Sorted array elements...\n";
    printArray(a,num);
    
    return 0;
}