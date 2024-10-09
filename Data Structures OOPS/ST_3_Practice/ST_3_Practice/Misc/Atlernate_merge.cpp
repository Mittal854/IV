#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];

    int mid=(n+1)/2;
    int i=0,j=mid;
    while(i<mid){
        cout << arr[i]<<" ";
        i++;
        if(j<n){
            cout << arr[j] << " ";
            j++;
        }
    }
    cout << endl;
}