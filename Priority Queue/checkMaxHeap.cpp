#include<iostream>
#include<queue>
using namespace std;

bool isMaxHeap(int input[ ],int n){

    for(int i=0;i<n;i++){
        int childIndex = i;
        int parentIndex = (childIndex-1)/2;

        if(input[i] > input[parentIndex]){
            return 1;
        }
    }
    return 0;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << (isMaxHeap(arr, n) ? "true\n" : "false\n");

    delete[] arr;
}