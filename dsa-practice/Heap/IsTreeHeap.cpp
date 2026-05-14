#include<iostream>
#include<vector>
using namespace std;
class Heap{
    public:
        int arr[100];
        int size=0;
        Heap *left,*right;
        void insert(int x){
            int idx=size;
            size++;
            arr[idx]=x;
            left=nullptr;
            right=nullptr;
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
        bool CBT(){
            
        }
        bool heapProperty(){

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
    Heap hp;
    for(int i=0;i<n;i++){
        hp.insert(arr[i]);
    }
    bool res=(hp.Cbt() && hp.heapProperty());
    cout<<res<<"\n";
    return 0;
}