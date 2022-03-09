#include<iostream>
using namespace std;// 102 345 2343 5555 21343
int BinarySearch(int a[ ],int size,int element){
    int si,ei,mid;
    si = 0;
    ei = size;

    for(int i=1;i<=size;i++){
        mid = (si+ei)/2;

        if(a[mid]==element){
            return mid+1;
        }

        else if(a[mid]>=element){
            ei = mid - 1;
        }
        else
            si = mid+1;

    }

    return -1;
}
int main(){
    int num,a[100],element,i;

    cout<<"How many elements you wants to enter : ";
    cin>>num;

    cout<<"Enter "<<num<<" elements...\n";
    for(i = 0;i<num;i++){
        cin>>a[i];
    }

    cout<<"Array elements...\n";
    for(i = 0;i<num;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    cout<<"Enter element to search : ";
    cin>>element;

    int ans = BinarySearch(a,num,element);
     if (ans == -1)
    {
        cout << element << " is not present in an array.";
    }
    else
        cout << element << " is present at " << ans << " index.";

    return 0;

}