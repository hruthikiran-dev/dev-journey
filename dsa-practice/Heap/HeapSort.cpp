#include<iostream>
using namespace std;
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
        heapify(maxy,arr,n);
    }
}
void heapSort(int arr[], int n){
            while(n>1){
                swap(arr[0],arr[n-1]);
                n--;
                int idx=0;
                while(true){
                    int child1=(idx*2)+1;
                    int child2=(idx*2)+2;
                    int maxy=idx;
                    if(child1<n && arr[child1]>arr[maxy])
                        maxy=child1;
                    if(child2<n && arr[child2]>arr[maxy])
                        maxy=child2;
                    if(maxy!=idx){
                        swap(arr[maxy],arr[idx]);
                        idx=maxy;
                    }
                    else{
                        break;
                    }
                }
            }
        }
int main(){
    int n;
    cout<<"Enter the size of an array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=(n/2)-1;i>=0;i--){
        heapify(i,arr,n);
    }
    cout<<"After heapifying: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    heapSort(arr,n);
    cout<<"After Sorting: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    return 0;
}