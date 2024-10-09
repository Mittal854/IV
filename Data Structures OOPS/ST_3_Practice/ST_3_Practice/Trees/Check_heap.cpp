#include<iostream>
#include<vector>
using namespace std;

int check_heap(int index,int n,vector<int>&arr,bool &ans){
    if(index>=n ) return INT_MIN;
    if(arr[index]==-1) return INT_MIN;
    int left=check_heap(index*2+1,n,arr,ans);
    int right=check_heap(index*2+2,n,arr,ans);
    if(arr[index]<left || arr[index]<right) ans=false;
    return arr[index];

}

int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    bool ans=true;

    for(int i=0;i<n;i++){
        if(arr[i]<0) ans=false;
    }
    check_heap(0,n,arr,ans);
    if(ans) cout <<"yes"<<endl;
    else cout<<"No"<<endl;
}
