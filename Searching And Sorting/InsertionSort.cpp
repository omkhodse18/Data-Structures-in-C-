#include <iostream>
using namespace std;

void printArray(int a[ ],int size){
    for (int i = 0; i < size; i++){
        cout << a[i] << " ";
    }
}

void InsertionSort(int a[ ],int size){
    int i,j,key;

    for(i=1;i<size;i++){
        key = a[i];
        j = i-1;
            for(j=i-1;j>=0 && a[j]>key;j--){
                a[j+1] = a[j];
            }
            a[j+1] = key;
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

    InsertionSort(a,num);
    cout << "Sorted array elements...\n";
    printArray(a,num);
    
    return 0;
}