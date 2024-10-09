#include<iostream>
#include<vector>
using namespace std;

void solve(vector<vector<int> >&arr,int rows,int cols,int i,int j, string ans){
    if(i<0 || i>=rows || j<0 || j>cols || arr[i][j]==0){
        return;
    } 
    if(i==rows-1 && j==cols-1){
        cout << ans<<endl;
        return;
    }
    arr[i][j]=0;
    solve(arr,rows,cols,i+1,j,ans+"D");
    solve(arr,rows,cols,i-1,j,ans+"U");
    solve(arr,rows,cols,i,j+1,ans+"R");
    solve(arr,rows,cols,i,j-1,ans+"L");
    arr[i][j]=1;
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
    solve(arr,rows,cols,0,0,"");

}