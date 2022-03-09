#include <iostream>
using namespace std;

void printArray(int a[ ],int size){
    for (int i = 0; i < size; i++){
        cout << a[i] << " ";
    }
}

void BubbleSort(int a[ ],int size){
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if(a[i]>a[j]){
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
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

    BubbleSort(a,num);
    cout << "Sorted array elements...\n";
    printArray(a,num);
    
    return 0;
}