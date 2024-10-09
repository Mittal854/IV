#include<iostream>
#include<vector>
#include<map>
using namespace std;

void maping(map<int,map<int,vector<int> > >&mp,int index,int n,vector<int>&arr,int col,int row){
    if(index>=arr.size() ) return;
    if(arr[index]==-1) return;
    mp[col][row].push_back(arr[index]);
    maping(mp,index*2+1,n,arr,col-1,row+1);
    maping(mp,index*2+2,n,arr,col+1,row+1);
}

int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    map<int,map<int,vector<int> > >mp;
    maping(mp,0,n,arr,0,0);
    vector<int>ans;
    for(auto it:mp){
        for(auto temp:it.second){
            sort(temp.second.begin(),temp.second.end());
            for(auto i:temp.second) ans.push_back(i);
        }
    }
    for( auto it:ans) cout << it<<" ";
    cout <<endl;
}

