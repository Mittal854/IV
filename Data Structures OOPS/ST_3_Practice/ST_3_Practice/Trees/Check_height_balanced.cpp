#include<iostream>
#include<vector>
using namespace std;

int check_balanced(bool &ans,int index,vector<int>&arr){
    if(index>=arr.size() ) return 0;
    if(arr[index]==-1) return 0;

    int left=check_balanced(ans,index*2+1,arr);
    int right=check_balanced(ans,index*2+2,arr);

    if(abs(left-right)>1){
        ans=false;
    }
    return max(left,right)+1;
}

int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    bool ans=true;
    check_balanced(ans,0,arr);
    if(ans) cout <<"yes"<<endl;
    else cout<<"No"<<endl;
    
}

