#include<iostream>
#include<vector>
using namespace std;

void rec(int n,int &ans){
    if(n<0){
        return;
    }else if(n==0){
        ans++;
        return;
    }
    rec(n-1,ans);
    rec(n-2,ans);
}

int main(){
    int n;
    cin >> n;
    int ans=0;
    // rec(n,ans);
    // cout << ans<<endl;

    // using dp
    vector<int>dp(n,-1);
    dp[n-1]=1;
    dp[n-2]=2;
    for(int i=n-3;i>=0;i--) dp[i]=dp[i+1]+dp[i+2];
    cout << dp[0]<<endl;

}