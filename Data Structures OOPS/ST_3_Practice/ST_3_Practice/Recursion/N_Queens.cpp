#include<iostream>
#include<vector>
using namespace std;

bool check(int i,int j,vector<vector<int> >&arr,int n){
    bool hor=true,ver=true,left=true,right=true;
    for(int k=0;k<n;k++){
        if(arr[i][k]==1)hor=false; 
        if(arr[k][j]==1) ver=false;
    }
    int row=i,col=j;
    while(row>=0 && col>=0){
        if(arr[row][col]==1) left=false;
        row--;
        col--;
    }

    row=i,col=j;
    while(row>=0 && col<n){
        if(arr[row][col]==1) right=false;
        row--;
        col++;
    }
    return hor && ver && left&&right;
}

void rec(int i,vector<vector<int> >&arr,int n){
    if(i==n){
        for(auto it:arr){
            for(auto it2:it) cout << it2<< " ";
            cout <<endl;
        }
        cout << endl;
        return;
    }
    for(int j=0;j<n;j++){
        if(check(i,j,arr,n)){
            arr[i][j]=1;
            rec(i+1,arr,n);
            arr[i][j]=0;
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<vector<int> > arr(n,vector<int>(n,0));
    rec(0,arr,n);
}