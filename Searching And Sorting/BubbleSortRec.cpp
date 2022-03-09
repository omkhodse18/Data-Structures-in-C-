#include <iostream>
using namespace std;

void printArray(int a[ ],int size){
    for (int i = 0; i < size; i++){
        cout << a[i] << " ";
    }
}

void BubbleSort(int a[ ],int size){
    if(size==0){
        return;
    }
    for(int i=0;i<size-1;i++){
        if(a[i]>a[i+1]){
            swap(a[i],a[i+1]);
        }
    }

    BubbleSort(a,size-1);
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

    BubbleSort(a,num);
    cout << "Sorted array elements...\n";
    printArray(a,num);
    
    return 0;
}