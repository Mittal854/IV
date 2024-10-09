#include<iostream>
#include<vector>
using namespace std;

void check_BST(int index,int n,vector<int>&arr,bool &ans,int lower,int upper){
    if(index>=n ) return ;
    if(arr[index]==-1) return ;
    check_BST(index*2+1,n,arr,ans,lower,arr[index]);
    check_BST(index*2+2,n,arr,ans,arr[index],upper);
    if(arr[index]>upper || arr[index]<lower) ans=false;
    return ;

}

int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    bool ans=true;

    check_BST(0,n,arr,ans,INT_MIN,INT_MAX);
    if(ans) cout <<"yes"<<endl;
    else cout<<"No"<<endl;
}
