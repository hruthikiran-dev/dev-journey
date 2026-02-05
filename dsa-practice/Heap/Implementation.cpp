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
            return;
        }
        void print(){
            for(int i=0;i<size;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};
int main(){
    heap h;
    h.insert(19);
    h.insert(50);
    h.insert(18);
    h.insert(80);
    h.insert(20);
    h.insert(1);
    h.print();
    return 0;
}