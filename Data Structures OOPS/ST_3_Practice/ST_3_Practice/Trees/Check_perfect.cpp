#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    bool ans=true;

    for(int i=0;i<n;i++){
        if(arr[i]<0) ans=false;
    }
    
    int temp=log2(n+1);
    if(log2(n+1)!=temp)ans=false;
    
    if(ans) cout <<"yes"<<endl;
    else cout<<"No"<<endl;
}

