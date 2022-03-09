#include <iostream>
using namespace std;

void printArray(int a[ ],int size){
    for (int i = 0; i < size; i++){
        cout << a[i] << " ";
    }
}

void merge(int a[ ],int si,int ei,int mid){
    int i,j,k,b[100];
    i=si;
    j=mid+1;
    k=i;

    while(i<=mid && j<=ei){
        if(a[i]<a[j]){
            b[k] = a[i];
            i++;
            k++;
        }
        else{
            b[k]=a[j];
            j++;
            k++;
        }
    }

    while(i<=mid){
        b[k]=a[i];
        i++;
        k++;
    }

    while(j<=ei){
        b[k]=a[j];
        j++;
        k++;
    }
    for(k=si;k<ei;k++){
        a[k]=b[k];
    }
}

void MergeSort(int a[ ],int si,int ei){
    if(si>ei){
        return;
    }
    else{

    int mid = (si+ei)/2;
    MergeSort(a,si,mid);
    MergeSort(a,mid+1,ei);
    merge(a,si,ei,mid);
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

    MergeSort(a,0,num);

    cout << "Sorted array elements...\n";
    printArray(a,num);
    
    return 0;
}