// Problem: K-th Smallest Element
// Platform: GeeksForGeeks / Interview Problem
// Pattern: Heap (Max Heap of size K)
// Key Insight:
// - The K-th smallest element is the largest among the K smallest elements.
// - Maintain a max heap of size K.
// - Insert first K elements into the heap.
// - For every remaining element:
//     if it is smaller than heap top, replace the heap top.
// - The heap top finally gives the K-th smallest element.
// Time: O(n log k)
// Space: O(k)


#include<iostream>
#include<vector>
using namespace std;
class heap{
    public:
        int arr[100];
        int size=0;
        void insert(int x){
            arr[size]=x;
            int n=size;
            size++;
            while(n>0){
                int parent=(n-1)/2;
                if(arr[parent]<arr[n]){
                    swap(arr[parent],arr[n]);
                    n=parent;
                }
                else
                    break;
            }
        }
        void pop(){
            if(size>0){
                swap(arr[0],arr[size-1]);
                size--;
                int i=0;
                while(true){
                    int child1=(i*2)+1;
                    int child2=(i*2)+2;
                    int maxy=i;
                    if(child1<size && arr[child1]>arr[i])
                        maxy=child1;
                    if(child2<size && arr[child2]>arr[i])
                        maxy=child2;
                    if(maxy!=i){
                        swap(arr[maxy],arr[i]);
                        i=maxy;
                    }
                    else{
                        break;
                    }
                }
            }
        }
        int top(){
            if(size==0)
                return -1;
            return arr[0];
        }
};
int main(){
    int n;
    cout<<"Enter the size of an array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the k value: ";
    int k;
    cin>>k;
    heap hp;
    for(int i=0;i<k;i++){
        hp.insert(arr[i]);
    }
    for(int i=k;i<n;i++){
        if(arr[i]<hp.top()){
            hp.pop();
            hp.insert(arr[i]);
        }
    }
    cout<<"The Kth smallest element is: "<<hp.top()<<"\n";
    return 0;
}