#include<iostream>
using namespace std;
int LinearSearch(int a[ ],int size,int element){
    for(int i=1;i<=size;i++){
        if(a[i]==element){
            return i+1;
        }
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

    int ans = LinearSearch(a,num,element);
     if (ans == -1)
    {
        cout << element << " is not present in an array.";
    }
    else
        cout << element << " is present at " << ans << " index.";

    return 0;

}