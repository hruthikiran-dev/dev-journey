
// Problem: Sum of Sum of All Subarrays
// Platform: GeeksForGeeks
// Pattern: Contribution Technique
// Key Insight:
// - Instead of generating all subarrays, count contribution of each element.
// - arr[i] appears in (i + 1) * (n - i) subarrays.
//   -> (i + 1): choices for starting index
//   -> (n - i): choices for ending index
// - Multiply contribution count with arr[i] and sum up.
// Time: O(n)
// Space: O(1) extra


#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=(i+1)*(n-i)*arr[i];
    }
    cout<<sum;
    return 0;
}