#include<iostream>
#include<vector>
using namespace std;

void rec(vector<int>&arr,int index,int cur,int&ans){
    if(index>=arr.size()){
        ans=max(ans,cur);
        return;
    }
    rec(arr,index+2,cur+arr[index],ans);
    rec(arr,index+1,cur,ans);

}

int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    int ans=0;
    rec(arr,0,0,ans);
    cout <<ans<<endl;

}