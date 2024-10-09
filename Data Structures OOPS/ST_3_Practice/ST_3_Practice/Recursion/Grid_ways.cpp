#include<iostream>
#include<vector>
using namespace std;

void rec(vector<vector<int> >&arr,int rows,int cols,int i,int j,int cur,int &ans){
    if(i>=rows || j>=cols) return;
    cur+=arr[i][j];
    if(i==rows-1 && j==cols-1){
        ans=min(cur,ans);
    }
    rec(arr,rows,cols,i+1,j,cur,ans);
    rec(arr,rows,cols,i,j+1,cur,ans);

}

int main(){
    int rows,cols;
    cin >> rows>>cols;
    vector<vector<int> > arr(rows,vector<int>(cols));
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cin >> arr[i][j];
        }
    }
    int ans=INT_MAX;
    rec(arr,rows,cols,0,0,0,ans);
    cout << ans<<endl;
}