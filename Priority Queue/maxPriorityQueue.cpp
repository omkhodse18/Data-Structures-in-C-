#include<iostream>
#include<vector>
using namespace std;

class priorityQueue{
    vector<int> pq;

    public:
    priorityQueue(){ }

    bool isEmpty(){
        return pq.size()==0;
    }

    int getSize(){
        return pq.size();
    }
    
    int getMax(){
        if(isEmpty()){
            return 0;
        }

        return pq[0];
    }

    void insert(int element){
        pq.push_back(element);

        int childIndex = pq.size()-1;

        while(childIndex > 0){
            int parentIndex = (childIndex-1)/2;

            if(pq[parentIndex] < pq[childIndex]){
                swap(pq[parentIndex],pq[childIndex]);
            }
            else{
                break;
            }

            childIndex = parentIndex;
        }
    }

    int remove(){
        if(isEmpty()){
            return 0;
        }

        int ans = pq[0];
        pq[0] = pq[pq.size()-1];
        pq.pop_back();

        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;

        while(leftChildIndex < pq.size()){
            int tempIndex = parentIndex;

            if(pq[leftChildIndex] > pq[tempIndex]){
                tempIndex = leftChildIndex;
            }

            if(rightChildIndex < pq.size() && pq[rightChildIndex] > pq[tempIndex]){
                tempIndex = rightChildIndex;
            }

            if(tempIndex == parentIndex){
                break;
            }

            swap(pq[parentIndex],pq[tempIndex]);
            // int temp =  pq[tempIndex];
            // pq[tempIndex] = pq[parentIndex];
            // pq[parentIndex] = temp;

            parentIndex = tempIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;

        }

        return ans;
    }
};

int main(){
    priorityQueue pq;
    pq.insert(23);
    pq.insert(100);
    pq.insert(2);
    pq.insert(3);
    pq.insert(230);
    pq.insert(21);
    pq.insert(96);

    cout<<pq.getSize()<<endl;
    cout<<pq.getMax()<<endl;

    while(!pq.isEmpty()){
        cout<<pq.remove()<<endl;
    }
}