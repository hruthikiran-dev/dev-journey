// Problem: Heap Implementation
// Platform: LeetCode
// Pattern: Sorting + Greedy
// Key Insight:
// - Maximum product comes from either:
//   (largest * second largest * third largest)
//   OR
//   (two smallest negatives * largest)
// Time: O(n log n)
// Space: O(1) extra


#include<iostream>
using namespace std;
class heap{
    public:
        int arr[100];
        int size=0;
        void insert(int x){
            int idx=size;
            size++;
            arr[idx]=x;
            while(idx>0){
                int parent=(idx-1)/2;
                if(parent>=0 && arr[parent]<arr[idx]){
                    swap(arr[parent],arr[idx]);
                    idx=parent;
                }
                else{
                    break;
                }
            }
        }
        int remove(){
            if(size==0) 
                return -1;
            int res=arr[0];
            swap(arr[0],arr[size-1]);
            size--;
            int idx=0;
            while(true){
                int child1=idx*2+1;
                int child2=idx*2+2;
                if(child1>=size)
                    break;
                int maxy=child1;
                if(child2<size && arr[child2]>arr[maxy])
                    maxy=child2;
                if(arr[idx]<arr[maxy]){
                    swap(arr[idx],arr[maxy]);
                    idx=maxy;
                }
                else
                    break;
            }
            return res;
        }
        void print(){
            for(int i=0;i<size;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<'\n';
}
void heapify(int i,int arr[], int n){
    int child1=(i*2)+1;
    int child2=(i*2)+2;
    if(child1>=n)
        return;
    int maxy=child1;
    if(child2<n && arr[child2]>arr[child1]){
        maxy=child2;
    }
    if(arr[maxy]>arr[i]){
        swap(arr[maxy],arr[i]);
        print(arr,n);
        heapify(maxy,arr,n);
    }
}
int main(){
    heap h;
    h.insert(19);
    h.insert(50);
    h.insert(18);
    h.insert(80);
    h.insert(20);
    h.insert(1);
    h.print();
    int res=h.remove();
    cout<<"Deleted element is: "<<res<<"\n";
    h.print();
    res=h.remove();
    cout<<"Deleted element is: "<<res<<"\n";
    h.print();
    
    //Heapify Algorithm 
    int n;
    cout<<"Enter the no.of nodes: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(n>1){
        for(int i=(n/2)-1;i>=0;i--){
            heapify(i,arr,n);
        }
    }
    else{
        cout<<"The elements already follow heap order properties";
    }
    return 0;
}