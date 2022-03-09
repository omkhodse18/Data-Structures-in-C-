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

    int getMin(){
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

            if(pq[parentIndex] > pq[childIndex]){
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else{
                break;
            }    
            childIndex = parentIndex;
        }
    }

    int remove(){
        int ans = pq[0];
        pq[0] = pq[pq.size()-1];
        pq.pop_back();

        int parentIndex = 0;
        int LCI = 2 * parentIndex + 1;
        int RCI = 2 * parentIndex + 2;

        while(LCI < pq.size()){
            int minIndex = parentIndex;

            if(pq[minIndex] > pq[LCI]){
                minIndex = LCI;
            }

            if(RCI < pq.size() && pq[minIndex] > pq[RCI]){
                minIndex = RCI;
            }

            if(minIndex == parentIndex){
                break;
            }

            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = minIndex;
            LCI = 2 * parentIndex + 1;
            RCI = 2 * parentIndex + 2;
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
    cout<<pq.getMin()<<endl;

    while(!pq.isEmpty()){
        cout<<pq.remove()<<endl;
    }
}