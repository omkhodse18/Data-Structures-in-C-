#include <iostream>
using namespace std;

void printArray(int a[ ],int size){
    for (int i = 0; i < size; i++){
        cout << a[i] << " ";
    }
}

void mergeSort(int a[], int size){
	if(size==0||size==1)
        return;
    int mid=size/2;
 
    for(int i=0;i<mid;i++)
        for(int j=mid;j<size;j++)
        {
            if(a[i]>a[j])
            {
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
      if(size%2==0)
    {
      mergeSort(a,mid);  
      mergeSort(a+mid,mid);
    }
    else{
        mergeSort(a,mid);
        mergeSort(a+mid,mid+1);
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

    mergeSort(a,num);

    cout << "Sorted array elements...\n";
    printArray(a,num);
    
    return 0;
}