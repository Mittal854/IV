#include<iostream>
#include<vector>
#include<map>
using namespace std;

void maping(map<int,int>&mp,int index,int n,vector<int>&arr,int cur){
    if(index>=arr.size() ) return;
    if(arr[index]==-1) return;
    if(mp.find(cur)==mp.end())mp[cur]=arr[index];
    maping(mp,index*2+1,n,arr,cur+1);
    maping(mp,index*2+2,n,arr,cur+1);

}

int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    map<int,int>mp;
    maping(mp,0,n,arr,0);
    for(auto it:mp){
        cout <<it.second<<" ";
    }
}