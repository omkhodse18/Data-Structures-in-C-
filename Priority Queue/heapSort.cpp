#include<iostream>
using namespace std;

void heapSort(int pq[ ],int n){
    for(int i=1;i<n;i++){
        int childIndex = i;
        while(childIndex > 0){
            int parentIndex = (childIndex-1)/2;
            if(pq[childIndex] < pq[parentIndex]){
                swap(pq[childIndex],pq[parentIndex]);
            }
            else{
                break;
            }
            childIndex = parentIndex;
        } 
    }

    int size = n;

    while(size > 1){
        int ans = pq[0];
        pq[0] = pq[size-1];
        pq[size-1] = ans;

        size--;

        int parentIndex = 0 ;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;

        while(leftChildIndex < size){
            int tempIndex = parentIndex;
            if(pq[leftChildIndex] < pq[tempIndex]){
                tempIndex = leftChildIndex;
            }

            if(rightChildIndex < size && pq[rightChildIndex] < pq[tempIndex]){
                tempIndex = rightChildIndex;
            }

            if(tempIndex == parentIndex){
                break;
            }

            swap(pq[tempIndex],pq[parentIndex]);

            parentIndex = tempIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }
    }
}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    } 

    heapSort(input, size);

    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    } 

    delete[] input;
}