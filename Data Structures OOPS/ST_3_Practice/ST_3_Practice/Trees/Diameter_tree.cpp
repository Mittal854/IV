#include<iostream>
#include<vector>
using namespace std;

int find_diameter(int index,int n,vector<int>&arr,int &ans){
    if(index>=n ) return 0;
    if(arr[index]==-1) return 0;
    int left=find_diameter(index*2+1,n,arr,ans);
    int right=find_diameter(index*2+2,n,arr,ans);
    int temp=left+right;
    ans=max(ans,temp);
    return max(left,right)+1;

}

int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    int ans=0,cur=0;
    cout <<endl;
    find_diameter(0,n,arr,ans);
    cout << ans<<endl;
}
