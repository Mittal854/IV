#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    if(n==1){
        cout <<arr[0]<<endl;
        return 0;
    }else if(n==2){
        cout << max(arr[0],arr[1])<<endl;
        return 0;
    }
    
    vector<int>dp(n,-1);
    dp[n-1]=arr[n-1];
    dp[n-2]=arr[n-2];
    for(int i=n-3;i>=0;i--){
        dp[i]=max(dp[i+1],dp[i+2]+arr[i]);
    }

    cout <<dp[0]<<endl;

}