#include<iostream>
#include<queue>
using namespace std;

void kSoretedArray(int input[ ],int n,int k ){
    priority_queue<int> pq;

    for(int i=0;i<k;i++){
        pq.push(input[i]);
    }

    int j=0;
    for(int i=k;i<n;i++){
        input[j] = pq.top();
        pq.pop();
        pq.push(input[i]);
        j++;
    }

    while(!pq.empty()){
        input[j] = pq.top();
        pq.pop();
        j++;
    }
}

int main(){
    int size;
    cin>>size;
    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    } 

    kSoretedArray(input, size, 3);

    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    } 

    delete[] input;
}