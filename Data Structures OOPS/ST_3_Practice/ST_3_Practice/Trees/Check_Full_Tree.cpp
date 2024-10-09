#include<iostream>
#include<vector>
using namespace std;

int rec(vector<int>&arr,int index,bool&ans){
    if(index>=arr.size() || arr[index]==-1) return -1;
    int left=rec(arr,index*2+1,ans);
    int right=rec(arr,index*2+2,ans);
    if((left==-1 && right!=-1) || (left!=-1 && right==-1)) ans=false;
    return arr[index];
}

int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    while(n>0 && arr[n-1]==-1)n--;
    bool ans=true;
    rec(arr,0,ans);
    if(ans) cout << "YES\n";
    else cout <<"NO\n";

}